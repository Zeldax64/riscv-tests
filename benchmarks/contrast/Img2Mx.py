def img():
	import numpy as np
	import cv2
	from matplotlib import pyplot as plt
	print("vai executar img")
	img=cv2.imread('lenawoutcontrast.bmp',0);
	height, width = img.shape
	arq=open('img.h','w')
	bufaux="unsigned char image["+str(height)+"]["+str(width)+"] = {"
	arq.write(bufaux)

	for x in range(height):
		arq.write("{")
		for y in range(width):
			buf= "%d" %(img[x][y])
			if(y!=width-1):
				buf=buf+","
			arq.write(buf)
		arq.write("}")
		if(x!=height-1):
			arq.write(",")
			arq.write("\n")
	bufaux="};"
	arq.write(bufaux)

	arq.close()
def result():
	import numpy as np
	import cv2
	from matplotlib import pyplot as plt
	print("vai executar result")
	img2=cv2.imread('lenaWithContrast.bmp',0);
	height, width = img2.shape
	arq=open('result.h','w')
	bufaux="unsigned char resultimage["+str(height)+"]["+str(width)+"] = {"
	arq.write(bufaux)

	for x in range(height):
		arq.write("{")
		for y in range(width):
			buf= "%d" %(img2[x][y])
			if(y!=width-1):
				buf=buf+","
			arq.write(buf)
		arq.write("}")
		if(x!=height-1):
			arq.write(",")
			arq.write("\n")
	bufaux="};"
	arq.write(bufaux)

	arq.close()

def main():
	img()
	result()
main()