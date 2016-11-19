#singleinstance Force

Gui, font, s18, Arial

Gui, add, text,x50 y50         , Initial Pos
Gui, add, text,x50 y100        , Molecule 1 x 
Gui, add, edit,x50 y150 w90 vPx1, 200
Gui, add, text,x50 y200        , Molecule 1 y
Gui, add, edit,x50 y250 w90 vPy1, 150
Gui, add, text,x50 y300        , Molecule 2 x 
Gui, add, edit,x50 y350 w90 vPx2, -200
Gui, add, text,x50 y400        , Molecule 2 y
Gui, add, edit,x50 y450 w90 vPy2, 100
Gui, add, text,x50 y500        , Molecule 3 x 
Gui, add, edit,x50 y550 w90 vPx3, -50
Gui, add, text,x50 y600        , Molecule 3 y
Gui, add, edit,x50 y650 w90 vPy3, 300
Gui, add, text,x50 y700        , Molecule 4 x
Gui, add, edit,x50 y750 w90 vPx4, 200
Gui, add, text,x50 y800        , Molecule 4 y
Gui, add, edit,x50 y850 w90 vPy4, -150

Gui, add, text,x350 y50         , Initial Vel
Gui, add, text,x350 y100        , Molecule 1 x Vel 
Gui, add, edit,x350 y150 w90 vVx1, -10
Gui, add, text,x350 y200        , Molecule 1 y Vel 
Gui, add, edit,x350 y250 w90 vVy1, 12
Gui, add, text,x350 y300        , Molecule 2 x Vel 
Gui, add, edit,x350 y350 w90 vVx2, 11
Gui, add, text,x350 y400        , Molecule 2 y Vel 
Gui, add, edit,x350 y450 w90 vVy2, -5
Gui, add, text,x350 y500        , Molecule 3 x Vel 
Gui, add, edit,x350 y550 w90 vVx3, 14
Gui, add, text,x350 y600        , Molecule 3 y Vel 
Gui, add, edit,x350 y650 w90 vVy3, -6
Gui, add, text,x350 y700        , Molecule 4 x Vel 
Gui, add, edit,x350 y750 w90 vVx4, 4
Gui, add, text,x350 y800        , Molecule 4 y Vel 
Gui, add, edit,x350 y850 w90 vVy4, 8

Gui, add, text,x650 y50        , Time
Gui, add, edit,x650 y100 w90 vTFinal, 80
Gui, add, text,x650 y150        , Number of Molecules
Gui, add, edit,x650 y200 w90 vNumMol, 4
Gui, add, text,x650 y250        , Collision Size
Gui, add, edit,x650 y300 w90 vSize, 1200
Gui, add, text,x650 y350        , Left Border
Gui, add, edit,x650 y400 w90 vLeft_b, -400
Gui, add, text,x650 y450        , Top Border
Gui, add, edit,x650 y500 w90 vTop_b, 400
Gui, add, text,x650 y550        , Right Border
Gui, add, edit,x650 y600 w90 vRight_b, 400
Gui, add, text,x650 y650        , Bottom Border
Gui, add, edit,x650 y700 w90 vBot_b, -400

Gui, add, button, x650 y750, Simulate
Gui, add, button, x650 y805, RandomSim
Gui, add, button, x650 y860, Close

GuiControl, -default, Close
Gui, Show,
Return




ButtonSimulate:

Gui, submit,
Gui, destroy

FileDelete, input_parameters.txt
FileAppend, %tfinal% %NumMol% %Size% %left_b% %top_b% %right_b% %bot_b%, input_parameters.txt

FileDelete, input_positions.txt
FileAppend, %px1% %py1% %px2% %py2% %px3% %py3% %px4% %py4%, input_positions.txt

FileDelete, input_velocities.txt
FileAppend, %Vx1% %Vy1% %Vx2% %Vy2% %Vx3% %Vy3% %Vx4% %Vy4%, input_velocities.txt

boxstartx := 180
boxstarty := 50
boxwidth := right_b - left_b + 20
boxheight := top_b - bot_b + 30
if (%boxwidth% > 1800 or %boxheight% > 1000)
{
MsgBox, Error, box size too large. Exiting. 
Gosub, ButtonClose
}

Run 3.exe
Reset:
Gui, font, s18, Arial

Gui, add, groupbox, x%boxstartx% y%boxstarty% w%boxwidth% h%boxheight%

Gui, add, picture, AltSubmit x90 y500, m1.png
Gui, add, picture, AltSubmit x90 y530, m2.png
Gui, add, picture, AltSubmit x90 y560, m3.png
Gui, add, picture, AltSubmit x90 y590, m4.png

Gui, add, button, x50 y200 w90, Show
Gui, add, button, x50 y300 w90, Reset
Gui, add, button, x50 y400 w90, Close
Gui, font, s18, Arial
GuiControl, -default, Close
Gui, Show, w1840 h940
Return


ButtonShow:
Loop, read, out_data.txt
{
Loop, parse, A_LoopReadLine, CSV
{ 
foo = %A_Index%
while (foo > 1)
{
	foo -= 2
}
if (foo == 0)
{
	DataFieldNum := floor((A_Index + 1)/2)
	y%DataFieldNum% = %A_LoopField%
}
else if (foo == 1)
{
	DataFieldNum := floor(A_Index/2)
	x%DataFieldNum% = %A_LoopField%
}
else
{
	MsgBox, Error with foo!
}

}

Loop, %NumMol%
{
posx%A_Index% := boxstartx + boxwidth/2 + x%A_Index%
posy%A_Index% := boxstarty + boxheight/2 - y%A_Index%
}

loop, %NumMol%
{
ControlMove, Static%A_Index%, posx%A_Index%, posy%A_Index%,,,
}

}
Listvars
Return

ButtonRandomSim:

Gui, submit,
Gui, destroy


Return



ButtonReset:
Gui, destroy
Gosub, Reset
Return

ButtonClose:
ExitApp
Return

/*
Loop, %NumMol%
{
CurrentMolecule = %A_Index%
if ( CurrentMolecule == DataFieldNum )
{
	foo := floor((DataFieldNum + 1)/2)
	x%foo% = %A_LoopField%
}
else
{
	foo := floor((DataFieldNum - 1)/2)
	y%foo% = %A_LoopField%
}

*/