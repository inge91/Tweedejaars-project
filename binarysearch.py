# binary search mage using 
def binarysearch(A,key,  imin, imax):
    """A is the dict, min_i the smallest possible index(so zero), max_i the biggest
    possible index"""
  # continue searching while [imin,imax] is not empty
    while (imax > imin):
      # calculate the midpoint for roughly equal partition 
      imid = midpoint(imin, imax)
 
      # determine which subarray to search
      if (A.keys()[imid] < key):# change min index to search upper subarray
          imin = imid + 1
      elif (A.keys()[imid] > key ):
          # change max index to search lower subarray
          imax = imid - 1
      else:
        # key found at index imid
        return A.keys()[imid]
    return A.keys()[imid]
    
# gives floored mid value of imin and imax
def midpoint(imin, imax):
    print imax+imin / 2
    return imax+imin / 2 

#binary sreach wrapper that searches te most obvious of 
def binarysearch_wrapper(dictionary, x, y, z, hiproll, hippitch):
    """dictionary is a dict in a dict in a dict in a dict in a dict...
       x is the x position we would like to get 
       y is the y position we would like to get
       z is the z position we would like to get
       hiproll and hippitch as well."""
    #get index of nearest x coordinate
    value = binarysearch(dictionary, x, 0, len(dictionary.keys()-1))
    newdict = dictionary[value]
    #get index of nearest y coordinate
    value = binarysearch(newdict, y, 0, len(newdict.keys()))
    newdict = newdict[value]
    #get index of nearest z coordinate
    value = binarysearch(newdict, z, 0, len(newdict.keys()))
    newdict = newdict[value]
    #get index of nearest hiproll
    value = binarysearch(newdict, hiproll, 0, len(newdict.keys()))
    newdict = newdict[value]
    #get index of nearest hippitch
    value = binarysearch(newdict, hippitch, 0, len(newdict.keys()))
    newdict = newdict[value]
    #return the final dict, being the dict with all the angles
    return newdict








