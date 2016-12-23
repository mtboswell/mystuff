import pystache
import yaml
import sys

if(__NAME__ =="__MAIN__"):

	datafilename = sys.argv[1]
	templatefilename = sys.argv[2]

	datafile = file(datafilename, 'r')
	templatefile = file(templatefilename, 'r')

	data = yaml.load(datafile)

	template = templatefile.read()

	print pystache.render(template, data)
