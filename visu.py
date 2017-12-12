#!/usr/bin/python3.4
# -*-coding:Utf-8 -*

import sys
import time
from tkinter import *
from math import *

win = Tk()
win.title("Lem-in")
lem = []
i = 0

try:
    while 1:
        lem.append(input())
        i += 1
except EOFError:
    pass
except ValueError:
    sys.exit(0)
try:
    assert "##start" in lem
except AssertionError:
    sys.exit(0)
j = 0
while j != i:
    print(lem[j])
    j += 1

label = Label(win)
canvas = Canvas(win, width=1600, height=1080)

COEF = 50
COEF_X = 0
COEF_Y = 0
COEN = 30

def draw_map():
    j = 0
    i = 1
    room = []
    coor = ()
    while "" != lem[j]:
        coor = lem[j].split(" ")
        room.append(coor)
        if j > 1 and '#' not in room[j][0] and '-' not in room[j][0]:
            x1 = (int(room[j][1]) + COEF_X) * COEF
            x2 = ((int(room[j][1]) + COEF_X) * COEF) + COEN
            y1 = (int(room[j][2]) + COEF_Y) * COEF
            y2 = ((int(room[j][2]) + COEF_Y) * COEF) + COEN
            canvas.create_rectangle(x1, y1, x2, y2, fill="green")
        if '-' in room[j][0] and '#' not in room[j][0]:
            room2 = room[j][0].split("-")
            while room[i][0] != room2[0]:
                i += 1
            xa = int(room[i][1])
            ya = int(room[i][2])
            x1 = (int(room[i][1]) + COEF_X) * COEF
            y1 = (int(room[i][2]) + COEF_Y) * COEF
            featurex1 = ceil(x1 + (COEN / 2))
            featurex2 = ceil(y1 + (COEN / 2))
            i = 1
            while room[i][0] != room2[1]:
                i += 1
            xb = int(room[i][1])
            yb = int(room[i][2])
            x2 = (int(room[i][1]) + COEF_X) * COEF
            y2 = (int(room[i][2]) + COEF_Y) * COEF
            featurey1 = ceil(x2 + (COEN / 2))
            featurey2 = ceil(y2 + (COEN / 2))
            canvas.create_line(featurex1, featurex2, featurey1, featurey2, fill="brown")
        i = 1
        j += 1
    j += 1
    return room, j

room, j = draw_map()
def draw_ant(room, j):
    i = 1
    while j < len(lem):
        tmp = lem[j].split(" ")
        k = 0
        while k < len(tmp):
            name = tmp[k].split("-")
            while len(name) > 1 and room[i][0] != name[1]:
                i += 1
                if room[i][0] == name[1]:
                    canvas.create_rectangle((int(room[i][1]) + COEF_X) * COEF,
                            (int(room[i][2]) + COEF_Y) * COEF,
                            ((int(room[i][1]) + COEF_X) * COEF) + COEN,
                            ((int(room[i][2]) + COEF_Y) * COEF) + COEN, fill="red")
                    canvas.update_idletasks()
                    time.sleep(1)
                    canvas.delete("all")
                    draw_map()
            i = 1
            k += 1
        j += 1

def inpt(event):
    global COEF
    global COEF_X
    global COEF_Y
    global COEN
    touche = event.keysym
    room, j = draw_map()
    if touche == "plus":
        COEF = COEF + 10
        COEN += 3
    if touche == "minus" and COEF > 20:
        COEF = COEF - 10
        COEN -= 3
    if touche == "Escape":
        sys.exit(0)
    if touche == "Left":
        COEF_X -= 1
    if touche == "Right":
        COEF_X += 1
    if touche == "Down":
        COEF_Y += 1
    if touche == "Up":
        COEF_Y -= 1
    if touche == "space":
        draw_ant(room, j)
    else:
        canvas.delete("all")
        draw_map()

canvas.bind_all("<Key>", inpt)
label.pack()
canvas.pack()
win.mainloop()
