import pylab as pl
import matplotlib.pyplot as plt
import os

def run():
    file_path = "data/triangles.txt"
    file_obj = open(file_path)
    lines = file_obj.readlines()
    for line in lines:
        pts_str = line.split(",")
        xs = []
        ys = []
        for pt_str in pts_str:
            pos_str = pt_str.split(" ")
            x = float(pos_str[0])
            y = float(pos_str[1])
            xs += [x]
            ys += [y]
        pos_str = pts_str[0].split(" ")
        x = float(pos_str[0])
        y = float(pos_str[1])
        xs += [x]
        ys += [y]
        plt.plot(xs,ys,'b-',lw=0.2)
    plt.show()

if __name__ == "__main__":
    run()