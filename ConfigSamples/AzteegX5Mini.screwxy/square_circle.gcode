
G0 X50
G0 Y50
G0 X0
G0 Y0


; circle, starting from bottom center
G0 X25 Y0
G03 Y50 J25
G03 Y0 J-25

; loop file
M32 square_circle.gcode
