from PIL import Image
from scipy import interpolate

width = 1100
height =1300
img = Image.new('RGB', (width,height),"black")
f = open("copyflat.ply",'r')
fp = open("copyflat.ply",'r')
#img.show()

pixels = img.load()
head = 1

max_x= -100000
min_x= 100000
max_y= -100000  
min_y=  100000

while True:
    line = f.readline()
    if not line:
        break          # no line to read
    if head ==0 :               # not header
        linearr = line.split(' ',2)
        x = float(linearr[0])
        y = float(linearr[1])
        #print(x,y)
        if x > max_x :
            max_x = x
        if x<min_x :
            min_x = x
        if y>max_y:
            max_y = y
        if y<min_y:
            min_y = y

    elif line == "end_header\n":    #end of the header
            head = 0
    else : 
        continue
#print (max_x,min_x,max_y,min_y)
#print (img.size[0],img.size[1])
#print (pixels[0,0])

act_width = max_x-min_x
act_height = max_y-min_y
head = 1
while True:
    line = fp.readline()
    if not line: break          # no line to read
    if head ==0 :               # not header
        linearr = line.split(' ',5)
        x = float(linearr[0])
        y = float(linearr[1])
        r = int(linearr[3])
        g = int(linearr[4])
        b = int(linearr[5])
       # print(int((width-1)*(x-min_x)/act_width),int((height-1)*(y-min_y)/act_height))
        pixels[int((width-1)*(x-min_x)/act_width) , int((height-1)*(y-min_y)/act_height)] = (r,g,b)

    elif line == "end_header\n":    #end of the header
            head = 0
    else : 
        continue
 
img.save("dem_mesh.png")
f.close()
fp.close()
