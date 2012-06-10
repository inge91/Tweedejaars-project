#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
Usage: python module_generator.py [options] module1 module2...
"""
import shutil
import os
import os.path
import sys
import re # for checking valid names
from optparse import OptionParser


from Tkinter import *
import Tix
from tkMessageBox import showwarning, showerror, askyesno

USAGE  = """module_generator [options] module1 module2..."""
CUR_DIR = os.path.abspath(os.path.dirname(__file__))
validNameRegexp=re.compile("^[A-Za-z_][A-Za-z0-9_]*$")

def isValidName(name):
  match = validNameRegexp.match(name)
  if match == None or match.group() != name:
    return False
  return True

def replaceInFile(fileName,fromString,toString):
  """
    Change lines in a file. Replaces:
      fromString by toString,
      fromstring by tostring,
      FROMSTRING by TOSTRING
  """
  # Be lazy:
  alreadyUp = (fromString.upper() == fromString)
  alreadyLow = (fromString.lower() == fromString )

  toWrite=[]
  file = open(fileName,"r")
  fromStringLow = fromString.lower()
  fromStringUp = fromString.upper()
  toStringLow = toString.lower()
  toStringUp = toString.upper()

  for line in file:
    beforeLine = line
    line = re.sub(fromString,toString,line)
    if not alreadyUp:
      line = re.sub(fromStringUp,toStringUp,line)
    if not alreadyLow:
      line = re.sub(fromStringLow,toStringLow,line)
    toWrite.append(line)

  file.close()

  file = open(fileName,"w")
  file.writelines(toWrite)
  file.close()




class Project:
    """ A Project container """
    def __init__(self, type, name, author, modules ):
        self.type = type
        self.name    = name
        self.name_lower = name.lower()
        self.author  = author
        self.modules = []
        for name in modules:
            if(name!=''):
                self.modules.append(Module(name))

    def isValid(self):
        if( len( self.name) < 1 ):
          return False
        if len (self.modules ) < 1 :
          return False
        if( not isValidName(self.name) ):
          print "the name of your project is not valid : " + self.name
          return False
        for module_name in self.modules:
          if( not isValidName(module_name.name) ):
            print "the name of one of your modules is not valid : " + module_name.name
            return False
        return True

class Module:
    """ A Module container """
    def __init__(self, name):
        self.name    = name
        self.description = "This is an auto-generated module, this" + \
        " description needs to be updated."
        self.methods = []

class Method:
    """ A Method container """
    def __init__(self, name, description):
        self.name        = name
        self.description = description
        self.parameters  = []
        self.returns     = None
        self.body        = None

class Parameter:
    """ A parameter container """
    def __init__(self, name, type, description):
        self.name        = name
        self.type        = type
        self.description = description

class Returns:
    """ A Returns container """
    def __init__(self, name, type, description):
        self.name        = name
        self.type        = type
        self.description = description

class ModuleGenerator:
    """ Generates NaoQi Modules """
    def __init__(self ,  project , outputdirectory):
        global CUR_DIR
        self.projectType = project.type.lower()
        print self.projectType
        self.output_directory = os.path.join(outputdirectory, project.name)
        if not os.path.exists(self.output_directory):
            os.makedirs(self.output_directory)
        self.template_path = os.path.join(CUR_DIR,"..","share","module_generator", "templates")
        self.template_path = os.path.join(self.template_path,self.projectType) + \
         os.path.sep

        self.project = project
        self.parser = None
        print  "project : "+ self.project.name
        print  "author_name : "+ self.project.author
        print  "modules_names : "
        for module in self.project.modules :
            print  "  "+ str( module.name)

    def copy_file(self, inputFile, outputFile ):
        """ Saves a file to a given path """
        inputFileFullPath = os.path.join( self.template_path , inputFile)
        outPath = os.path.join(self.output_directory, outputFile)
        shutil.copyfile(inputFileFullPath, outPath)
        return outPath

    def generate(self):
      # main
      outputFile = "main.cpp"
      outputFileFullPath = self.copy_file("main.cpp.tmpl", outputFile )
      replaceInFile( outputFileFullPath , "Project_Name" , self.project.name)
      replaceInFile( outputFileFullPath , "Author_Name" , self.project.author )

      #Build string to replace string: "Create modules instances"
      stringModulesCreation = ""
      for module in self.project.modules:
        stringModulesCreation += "  AL::ALModule::createModule<" + module.name + ">( pBroker, \"" + module.name + "\" );\n"
      replaceInFile( outputFileFullPath , "Create_Module_Instances" , stringModulesCreation )

      #Build string to replace string: "add modules include"
      stringModulesCreation = ""
      for module in self.project.modules:
        stringModulesCreation += "#include \"" + module.name.lower() + ".h\"\n"
      replaceInFile( outputFileFullPath , "Add_Module_Includes" , stringModulesCreation )

      # cmake
      outputFile = "CMakeLists.txt"
      outputFileFullPath = self.copy_file("CMakeLists.txt.tmpl", outputFile )
      replaceInFile( outputFileFullPath , "Project_Name" , self.project.name)
      #Build string to replace string: "Add_Module_Files"
      stringModulesCreation = ""
      for module in self.project.modules:
        stringModulesCreation += "  " + module.name + ".h\n"
        stringModulesCreation += "  " + module.name + ".cpp\n"
      replaceInFile( outputFileFullPath , "Add_Module_Files" , stringModulesCreation )

      # modules
      for module in self.project.modules:
          self.generate_module(module.name)

    def generate_module(self,moduleName):
      outputFile = moduleName.lower() + ".cpp"
      outputFileFullPath = self.copy_file("module.cpp.tmpl", outputFile )
      replaceInFile( outputFileFullPath , "Module_Name" , moduleName )
      replaceInFile( outputFileFullPath , "Author_Name" , self.project.author )
      replaceInFile( outputFileFullPath , "add_module_header" , "#include \""+moduleName.lower()+".h\"\n"  )

      outputFile = moduleName.lower() + ".h"
      outputFileFullPath = self.copy_file("module.h.tmpl", outputFile )
      replaceInFile( outputFileFullPath , "Module_Name" , moduleName )
      replaceInFile( outputFileFullPath , "Author_Name" , self.project.author )
      replaceInFile( outputFileFullPath , "Project_Name" , self.project.name)

      outputFile = "test.py"
      outputFileFullPath = self.copy_file("test.py.tmpl", outputFile )
      replaceInFile( outputFileFullPath , "Module_Name" , moduleName )
      replaceInFile( outputFileFullPath , "Author_Name" , self.project.author )
      replaceInFile( outputFileFullPath , "Project_Name" , self.project.name)

      outputFile = "qiproject.xml"
      outputFileFullPath = self.copy_file("qiproject.xml.tmpl", outputFile)
      replaceInFile( outputFileFullPath , "projectname" , self.project.name.lower())



class ModuleGeneratorGUI():
    """
    Tkinter GUI for the module generator.
    """

    def __init__(self,generatorFunction):

        # Keep the generation function in memory
        self.generatorFunction = generatorFunction
        self.build()
        # The folder hierarchy will look like this when installed:
        # <prefix>
        #    |__ bin/
        #    |    |__ module_generator.py
        #    |__  examples
        #         |__ motion
        #         ...
        #         |__ audio
        #         ...
        #
        # So let just write the module to
        # <prefix>/examples/generated/<modulename>
        base_dir = os.path.abspath(os.path.dirname(__file__)) # bin/
        output_dir  = os.path.join(base_dir, "..", "output")
        output_dir  = os.path.abspath(output_dir)
        if not os.path.exists(output_dir):
            os.makedirs(output_dir)
        self.output_dir = output_dir

    def __del__(self):
        self.root.destroy()

    def display(self):
        print varcombo.get()


    def build(self):

        # Building main window
        self.root = Tix.Tk()
        self.type = "Module"
        self.root.title("Module Generator")
        self.root.resizable(width=False, height=False)

        # Setting window size
        w = 350
        h = 200

        # Get screen width and height
        ws = self.root.winfo_screenwidth()
        hs = self.root.winfo_screenheight()

        # Calculate position x, y
        x = (ws/2) - (w/2)
        y = (hs/2) - (h/2)
        self.root.geometry('%dx%d+%d+%d' % (w, h, x, y))

        # Setting entry variables
        self.project = StringVar()
        self.author = StringVar()
        self.modules = StringVar()

        # Main frame of the window
        self.frame = Tix.Frame(master=self.root)
        self.frame.pack(fill=X,padx=10,pady=5)

        # Tip for modules
        tipLabel = Label(self.frame, text="Module names should be separated by whitespace.")
        tipLabel.grid(column=0,row=0,pady=5,columnspan=3)

        # Project
        projectLabel = Label(self.frame,text="Project name :")
        projectLabel.grid(column=0,row=1,pady=5)
        self.projectInput = Entry(self.frame,textvariable=self.project)
        self.projectInput.bind("<Return>",self.validate)
        self.projectInput.grid(column=1,row=1,columnspan=2,pady=5)

        # Author
        authorLabel = Label(self.frame,text="Author name :")
        authorLabel.grid(column=0,row=2,pady=5)
        self.authorInput = Entry(self.frame,textvariable=self.author)
        self.authorInput.bind("<Return>",self.validate)
        self.authorInput.grid(column=1,row=2,columnspan=2,pady=5)

        # Modules
        modulesLabel = Label(self.frame,text="Modules name :")
        modulesLabel.grid(column=0,row=3,pady=5)
        self.modulesInput = Entry(self.frame,textvariable=self.modules)
        self.modulesInput.bind("<Return>",self.validate)
        self.modulesInput.grid(column=1,row=3,columnspan=2,pady=5)

        # Module type
        typeLabel = Label(self.frame,text="Modules Type :")
        typeLabel.grid(column=0,row=4,pady=5)

        # type combobox
        self.combo = Tix.ComboBox(self.frame, variable=self.type)
        self.combo.grid(column=2,row=4,pady=5)

        color_list = ['Module', 'Video', 'Audio']
        for item in color_list:
                self.combo.slistbox.listbox.insert('end', item)
        self.combo.configure(value='Module')

        # Validation
        self.validateButton = Button(self.frame,text="Generate",command=self.validate)
        self.validateButton.grid(column=2,row=5,pady=5)

    def validate(self,*args):

        # Check if fields are filled
        for moduleName in self.modules.get().split():
            if (moduleName == self.project.get()):
                showerror("Generator error","Modules and project must have different names")
                return

        if self.project.get() == "" or self.modules.get() == "":
            showwarning("Incomplete form",
                        "Please ensure project name and modules names are given.")
        else:
            # Generate project !
            status, message = self.generatorFunction(self.combo.entry.get(), self.project.get(),
                                self.author.get(), self.output_dir, self.modules.get().split())
            if status:
                if askyesno("Generation complete",
                            "%s\nDo you want to quit?" % message):
                    self.quit()
            else:
                showerror("Generator error", message)

    def mainloop(self):
        self.root.mainloop()

    def quit(self):
        self.frame.quit()



def generate(type, project, author, dir, modules):
    if (project.find(" ") > 0):
        return (False,"Project name musn't contain spaces")

    for c in project:
       if (not isValidName(c)):
	        return (False,c + " is not a valid project character")

    for m in modules:
 	for c in m:
	       if (not isValidName(c)):
		        return (False,c + " is not a invalid module character")
    current_project = Project(type, project, author, modules)
    if(current_project.isValid()):
        module_generator = ModuleGenerator(current_project , dir)
        module_generator.generate()
        out = os.path.join(dir, project)
        return (True,"Project generated in: %s" % out)
    else:
        return (False,"Please set valid options !")

def main():
    """
    Parses command line options.
    If no option given, a wizard is shown to help the user.
    """
    parser = OptionParser(usage=USAGE, version="1.0")
    parser.add_option("-p", "--project",
                           type="string",
                           action="store",
                           dest="projectname",
                           help="Project Name",
                           default="ExampleProject")
    parser.add_option("-a", "--author",
                           type="string",
                           action="store",
                           dest="authorname",
                           default="Author",
                           help="Author Name")
    parser.add_option("-o", "--output-directory",
                           type="string",
                           action="store",
                           dest="outputdirectory",
                           default=os.getcwd() + os.path.sep,
                           help="Output Directory")

    parser.add_option("-t", "--protect-type",
                           type="string",
                           action="store",
                           dest="projectType",
                           default="Module",
                           help="Type of project: module, video, audio")

    (options, args) = parser.parse_args()
    outputdirectory = options.outputdirectory
    outputdirectory = os.path.abspath(outputdirectory)

    if (sys.argv[1:] ):
        result, message = generate(options.projectType, options.projectname, options.authorname,
                            outputdirectory, args)
        print message
        if not result:
            print USAGE
    else:
        mainWindow = ModuleGeneratorGUI(generate)
        mainWindow.mainloop()
        del mainWindow

if __name__ == "__main__":
    main()

