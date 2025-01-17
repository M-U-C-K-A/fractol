
						┌───────────────┐
						│	FRACTOL		│
						└───────╥───────┘
								║
	┌───────────────────────────╨─────────────────────────────┐
	│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│
	│░░░░░░░░░░░░░░░░░░░░ Fractol Engine ░░░░░░░░░░░░░░░░░░░░░│
	│░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░│
	└───────────────────────────┬─────────────────────────────┘
								│
								▼
		┏━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
		┃													┃
		▼													▼
╔═══════════════════╗							╔══════════════════════╗
║░░░ USER EVENTS ░░░║							║░░░░░░ FRACTALS ░░░░░░║
╟───────────────────╢							╟──────────────────────╢
║ [on_destroy]      ║		  INPUTS			║ [mandelbrot]         ║
║ [on_mouse_hook]   ║ <═════════╦═════════════> ║ [julia]              ║
║ [on_key_hook]     ║			║				║ [burning_ship]       ║
║ [on_mousemove]    ║			║				║ [tricorn]            ║
║───────────────────║			║				║ [celtic_mandelbar]   ║
║ Handles user      ║			║				║ [mandelbox]          ║
║ interactions.     ║			║				╟──────────────────────╢
╚═══════════════════╝			║				║ Computes fractal     ║
								║				║ values based on      ║
								║				║ complex coordinates. ║
								▼				╚══════════════════════╝
					╔════════════════════════╗
					║░░░░░░░░ ENGINE ░░░░░░░░║
					╟────────────────────────╢
					║ [change_fractal]       ║
					║ [set_fractal_type]     ║
					║ [reset_engine]         ║
					║ [init_engine]          ║
					╟────────────────────────╢
					║ Manages core logic:    ║
					║ selecting fractals,    ║
					║ resetting parameters,  ║
					║ initialization.        ║
					╚════════════════════════╝
								║
			╔═══════════════════╩═════════════════════╗
			║										  ║
			▼										  ▼
	╔════════════════╗						╔═══════════════════╗
	║░░░░ RENDER ░░░░║						║░░░░ UTILITIES ░░░░║
	╟────────────────╢						╟───────────────────╢
	║ [set_pixel]    ║						║ [error_message]   ║
	║ [change_color] ║						║ [ft_strlower]     ║
	║ [change_view]  ║			OUTPUTS		║ [print]           ║
	║ [draw_fractal] ║	══════════════════>	║ [show_help]       ║
	╟────────────────╢						╟───────────────────╢
	║ Handles pixel  ║						║ Helper functions  ║
	║ colors, zoom,  ║						║ for errors, text, ║
	║ pan, and full  ║						║ and help display. ║
	║ fractal draw.  ║						╚═══════════════════╝
	╚════════════════╝
