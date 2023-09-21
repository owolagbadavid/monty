						set up cell blocks 0 | 70 | 100 | 10:
+++++ +++++				cell 0: initialize counter to 10
[						set loop
	> +++++ +++			cell 1: add 7
	> +++++ +++++		cell 2: add 10
	> +					cell 3: add 1
	<<< -				decrease counter to cell 0
]						end loop

						print to standard out:
> +++ .					putchar S (80 plus 3 = 83)
> - .		putchar c (100 minus 1 = 99)
+++++ .					putchar h (99 + 5 = 104)
+++++ + .			putchar o (104 plus 7 = 111)
.					putchar o (same)
--- .		putchar o (111 minus 3 = 108)
> .						putchar \n (10)
