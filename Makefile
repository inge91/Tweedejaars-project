NAME = report

all:
	pdflatex ${NAME}
	bibtex ${NAME}
	pdflatex ${NAME}
	pdflatex ${NAME}

