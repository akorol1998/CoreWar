.name "Petrovich"
.comment "Agregat is my best friend!"

mess:
	ld 0, r1
	st r1, 321
	live %322

live:
	live %322
	ld %45, r2
	sti r2, %123, %123

jump:
	zjmp %:mess
	