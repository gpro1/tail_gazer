/*  GIMP header image file format (RGB): D:\Gregory\Pictures\Androtchi_sprite.h  */

static unsigned int width = 16;
static unsigned int height = 16;

/*  Call this macro repeatedly.  After each use, the pixel data can be extracted  */

#define HEADER_PIXEL(data,pixel) {\
pixel[0] = (((data[0] - 33) << 2) | ((data[1] - 33) >> 4)); \
pixel[1] = ((((data[1] - 33) & 0xF) << 4) | ((data[2] - 33) >> 2)); \
pixel[2] = ((((data[2] - 33) & 0x3) << 6) | ((data[3] - 33))); \
data += 4; \
}
static char *robot_normal =
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!U+!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)S-D)S-D)S-D)S-D)!!!!S-D)!!!!%\"!1!!!!!!!!%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)!!!!S-D)S-D)S-D)S-D)S-D)!!!!%\"!1!!!!%\"!1%\"!1"
	"!!!!!!!!%\"!1!!!!S-D)S-D)!!!!!!!!!!!!S-D)S-D)!!!!!!!!!!!!!!!!%\"!1"
	"%\"!1!!!!!!!!!!!!S-D)S-D)S-D)S-D)S-D)S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"!!!!!!!!%\"!1!!!!S-D)S-D)!!!!!!!!!!!!S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!AI+#!!!!%\"!1%\"!1%\"!1!!!!AI+#!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1"
	"";

static char *robot_mad =
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1$AY/$Q]0%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1"
	"!!!!%\"!1!!!!%\"!1%\"!1%\"!1!!!!U+!!!!!!%\"!1%\"!1%\"!1!!!!%\"!1!!!!%\"!1"
	"!!!!!!!!!!!!%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1%\"!1%\"!1!!!!!!!!!!!!%\"!1"
	"%\"!1!!!!%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1!!!!%\"!1%\"!1"
	"%\"!1!!!!%\"!1!!!!S-D)!!!!S-D)S-D)S-D)!!!!S-D)!!!!%\"!1!!!!%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!S-D)!!!!!!!!S-D)!!!!!!!!S-D)!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)S-D)S-D)S-D)S-D)S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)S-D)!!!!!!!!!!!!S-D)S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!S-D)!!!!!!!!!!!!!!!!!!!!S-D)!!!!%\"!1%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!Q!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1!!!!%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1!!!!%\"!1%\"!1%\"!1"
	"%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1%\"!1!!!!%\"!1%\"!1%\"!1%\"!1"
	"";

static char *rainbow =
	"`Q!*`Q!H`Q&(`Q&H`Q'&`Q'F`Q$%`Q(E_Q$`X1$`P!(`HA(`@A(`8A$`0Q$`)!(`"
	"!!(`!#$`!%@`!'<`!)<`!;8`!-8`!/4`!@`]!0`=!0_^!0_>!0^_!0^@!@]`!0]A"
	"!0]!)0]\"0`]\"8`]!@P]\"HP]!P@]!X0]\"_`]!`_1!`]1\"`[5\"`Y9!`W=!`U=\"`S=!"
	"`Q%I`Q!X`Q&0`Q\"P`Q'/`Q'N`Q$-`Q$M^!(`V!(`N1$`F1$`>A$`6Q$`.Q(`'!(`"
	"!!D`!3D`!5@`!7@`!)<`!;8`!-8`!?4`!@`]!0`=!0_]!0_>!0^_!0^?!@]`!@]A"
	"!@]\")0]!10]\"8P]\"@P]!H@]!P@]!X0]\"_`]\"`_1!`]5\"`[9\"`Y9!`W9\"`U=\"`SA\""
	"`Q\"(`Q\"0`Q\"G`Q\"_`Q'7`Q#V`Q$5`Q(U^!(`V!(`N!(`F1(`>Q$`6Q(`/!$`'!$`"
	"!1D`!#D`!5@`!7@`!9<`!;8`!=8`!?4`!@`]!0`=!0_^!@_>!0^_!0^?!@^!!0]A"
	"!0]!)0]!0`]\"8`]!@P]\"H@]\"P@]\"X@]\"`0]\"`_1\"`]5\"`[9!`Y9!`W=!`U=!`S!\""
	"`Q&H`Q&O`Q\"_`Q#6`Q#N`Q$&`Q$>`Q(]Z1(`T!$`L1$`DA(`<A(`4Q(`-!(`%!$`"
	"!\"$`!3``!5``!'\\`!9X`!+X`!=X`!?T`!0`U!@`5!0_V!0_7!@^X!0^7!@]Y!0]9"
	"#@]!*`]\"30]\":`]\"BP]!J@]\"R@]\"Z0]\"``M\"`^Q!`\\U\"`ZU\"`XY\"`VY!`T]\"`S!\""
	"`Q''`Q'/`Q'7`Q#N`Q'^`Q(6`Q(M]Q$`X!(`P1(`H1(`BA$`:Q$`2Q$`*Q(`#1$`"
	"!\"D`!$D`!5``!7``!9X`!;X`!=T`!?T`!@`U!0`5!@_V!@_6!@^W!@^8!@]Y!0]9"
	"#@]\"*`]\"2`]\":`]!B@]\"J@]!R0]!Z0]\"``M!`^Q\"`\\U!`ZY\"`X]!`VY!`T]!`S!!"
	"`Q#F`Q#N`Q'V`Q(%`Q(5`Q$M_Q(`Z!$`T1$`L1$`F1(`>A(`6Q(`1!(`)!(`!1$`"
	"!#$`!$``!&@`!(<`!*8`!<8`!>4`!@4`!@`M!@`-!0_N!@_/!0^P!@^0!@]P!@]1"
	"%0]!,`]!4`]\"<P]!DP]\"J@]!R0]\"Z0]!``Q!`^Q!`\\U\"`ZU\"`XY\"`VY!`U!!`S!!"
	"`Q$%`Q$.`Q(6`Q(=`Q(M`!(`Z!$`T!$`N1$`H1$`BA(`:A(`4Q$`,Q(`%!(`!!D`"
	"!3D`!5@`!7@`!)<`!:\\`!<X`!.X`!0P`!@`E!@`%!0_G!0_'!@^G!0^0!0]Q!@]2"
	"%0]\"-0]\"4`]!<P]!DP]\"L@]\"T@]\"\\0]\"``1!`^1!`\\5\"`Z9!`X9!`V=!`TA!`RA\""
	"`Q$E`Q$M`Q(U`Q(\\^!(`Z!(`T!$`P!(`J1$`D1(`<A$`6Q(`0Q$`)!(`#!$`!2D`"
	"!$D`!5\\`!7``!)\\`!;X`!-4`!/4`!@`]!0`=!0_^!0_>!@^_!0^G!@^(!@]H!@])"
	"'0]!/0]\"6`]\">P]!F@]\"N@]!V0]\"^0]\"`_Q\"`]U\"`[U\"`YY\"`WY!`U]!`T!!`R!!"
	"`!(`^!(`^!(`Z!$`X!(`T1$`N1(`J1(`DA$`>Q$`8A$`2Q$`,Q$`%1(`!!D`!3D`"
	"!$``!&\\`!8\\`!*<`!,8`!.8`!@4`!0`U!0`5!@_V!@_7!0^W!@^8!@]`!0]A!0]\""
	")0]!0`]\"8`]!@P]!H@]\"P@]!X@]\"_`]!`_Q\"`]U\"`[U\"`YY!`W]!`U]\"`S]!`R!!"
	"X!$`V1$`V!$`T1$`P1(`L1(`H1$`D1(`>A$`8Q$`2Q(`,Q$`'!(`!!$`!2D`!$D`"
	"!5``!7``!9<`!+8`!=8`!>T`!@T`!@`E!0`%!0_N!0_/!@^O!@^0!0]P!0]9#@]!"
	"*`]\"30]\":P]\"BP]!J@]!R@]!X0]!`0]\"`_1!`]5!`[5\"`Y5!`W=!`U=!`SA!`QA\""
	"P1(`N1(`N1$`L1(`HA(`FA$`BA$`<A(`8A(`2Q$`.Q$`)!$`#!(`!2$`!3``!5@`"
	"!&``!(\\`!:8`!,8`!-X`!?T`!0`U!0`>!@_^!0_>!@_'!@^H!@^(!@]I!@])%0]\""
	"-0]\"4`]\"<P]\"DP]\"L@]!T@]\"Z0]!``Q!`^Q!`\\U!`ZU!`XY\"`VY!`T]\"`R]\"`Q!\""
	"HA(`F1$`F1$`DA$`BA$`>A$`:A(`6Q$`2Q$`-!(`)!(`#!(`!\"$`!#D`!$``!6<`"
	"!8<`!)\\`!;8`!-8`!>X`!0T`!0`M!0`-!@_N!0_6!0^W!0^8!0]`!0]A!@]!)0]\""
	"0`]!6`]!>P]\"FP]!N@]\"V0]!^0]!``1!`^1!`\\5!`Z9\"`X9!`V=!`T=!`RA\"`Q%\""
	"@Q$`>A$`>A(`<Q$`:A(`6Q$`4Q$`0Q(`-!(`'!(`#!(`!2$`!#D`!%$`!&@`!'``"
	"!9<`!*\\`!<X`!.4`!?T`!0`U!0`=!@_^!@_F!@_'!@^G!0^0!@]Q!0]1#@]\"*`]\""
	"2`]!:P]\"@P]!H@]\"P@]\"X0]\"_`]\"`_1!`]U!`[U\"`YY!`W]\"`U]\"`S]\"`R!\"`Q!!"
	"8Q$`6Q$`6A$`4Q$`2Q(`0Q$`-!$`)!$`%!$`!!$`!2(`!#D`!4``!%``!'<`!(\\`"
	"!*8`!,8`!=X`!?4`!0T`!@`E!0`.!@_N!@_7!0^W!0^?!0]`!@]A!0])'0]\"/0]\""
	"4`]!<P]!DP]!L@]!R0]\"Z0]\"``Q!`^U\"`\\U!`[5\"`Y9\"`W=\"`U=!`SA\"`QA!`Q!\""
	"0Q$`/!(`.Q$`-!(`+!(`)!$`%!$`#!(`!!D`!2D`!#``!%$`!&@`!7<`!8\\`!*<`"
	"!+X`!-8`!.T`!04`!@`M!@`6!@_^!@_?!@_'!@^G!@^0!0]Q!@]9#0]\"*`]!0`]!"
	"8P]\"@P]\"F@]!N@]\"V0]\"^0]!``1!`^1!`\\5\"`Z9!`X9\"`V]!`T]!`S!!`Q!\"`Q!\""
	")!$`'!$`'!(`%!(`#1(`!1$`!!D`!2D`!3D`!$D`!%D`!&@`!'\\`!(\\`!*8`!;X`"
	"!=4`!>T`!@0`!0`U!@`=!0`&!@_F!0_/!0^W!0^8!@]`!0]A!0])'0]\",`]!4`]!"
	"<P]\"BP]\"J@]\"R0]!X0]\"_`]!`_1!`]5\"`[U!`YY!`WY\"`U]!`T=!`RA!`Q!\"`Q%!"
	"!1(`!!D`!1H`!2(`!\"D`!#$`!#@`!$D`!$``!5``!6``!(<`!)<`!*<`!;X`!=4`"
	"!.T`!?P`!@`\\!@`E!0`%!0_N!@_7!0^_!0^?!@^)!0]Q!@]1#0]!*`]!10]\"8P]\""
	">P]!F@]\"N0]\"T@]\"\\0]\"``1!`^Q!`\\U\"`ZU!`XY!`W9!`U=\"`SA\"`QA\"`Q!!`Q%\""
	"!#$`!3D`!#D`!#``!4@`!4``!%@`!5``!&``!'``!(\\`!)\\`!*X`!,8`!-4`!>T`"
	"!/T`!0`\\!@`E!0`.!@_V!0_>!0_'!0^H!@^0!@]X!0]A!@]\"'0]\"/0]!4`]!<`]!"
	"BP]\"J@]\"P@]!X0]!`0]!`_Q!`]Q\"`[U\"`Z5!`X9!`V=!`T=\"`S!!`Q!\"`Q!\"`Q%!"
	"!%@`!%@`!5@`!%``!%``!&@`!7@`!7\\`!8\\`!9<`!*8`!;8`!,X`!=X`!>T`!@0`"
	"!0`\\!0`E!0`.!0_V!@_>!@_'!@^O!0^8!0]`!0]H!@])%@]\"+0]!2`]!8`]\"@P]!"
	"FP]!N@]\"T@]\"\\0]\"``Q!`^Q!`\\U\"`[5\"`Y9!`W=!`U]!`S]!`R%!`Q!!`Q%!`Q%\""
	"!'<`!7@`!7@`!'\\`!7``!(@`!9<`!)X`!*<`!+<`!<8`!=4`!>4`!/4`!00`!@`U"
	"!0`E!@`.!@_V!@_>!0_'!@^X!@^?!@]`!@]I!0]1#0]\")0]!0`]\"6`]\"<`]!DP]\""
	"J@]\"R@]\"X0]!`0]\"`_Q\"`]U!`\\5\"`Z5\"`X=\"`V]\"`T]\"`S!\"`QA\"`Q!\"`Q%\"`Q!\""
	"!)<`!9<`!)<`!9\\`!9\\`!*<`!*X`!;X`!<8`!-8`!=X`!.T`!?T`!@T`!0`M!@`="
	"!@`&!@_V!0_>!@_'!@^W!0^@!0^(!@]Q!0]9!0]\")0]!.`]!4`]\":P]!BP]\"H@]!"
	"N@]!V0]\"\\0]!``-\"`^Q\"`\\U!`[9!`Y5\"`WY\"`U]\"`T!\"`RA\"`Q!!`Q%\"`Q%\"`Q!!"
	"!;8`!;8`!;8`!+X`!+X`!,8`!,X`!=8`!>8`!.T`!/T`!0T`!0`T!0`E!@`5!@`&"
	"!@_O!@_>!0_'!0^W!@^?!@^)!0]P!@]9!@]\"'0]!-0]!2`]!8`]\"@P]!FP]\"L@]\""
	"T@]\"Z0]!_`]\"`_1\"`]Q\"`[U\"`Z9\"`X9!`VY!`U!!`S=!`QA\"`Q%!`Q!!`Q%\"`Q%\""
	"!=4`!-4`!=8`!=T`!=T`!>4`!.T`!?4`!04`!@T`!@`T!@`M!@`>!0`-!0_]!0_G"
	"!@_7!@_'!@^P!@^@!@^(!@]Q!0]9!0]!'0]\"-0]\"2`]!8`]!>P]\"D@]\"J@]\"P@]\""
	"X0]!]`]\"``1\"`^5!`\\U!`ZY\"`Y5\"`W9\"`U]\"`T!!`RA!`Q%\"`Q!\"`Q!!`Q!\"`Q!\""
	"!/4`!/4`!/8`!?T`!/T`!00`!@P`!@`]!@`U!@`E!@`=!0`-!0_^!@_N!0_>!0_/"
	"!@^_!0^G!0^8!0^!!0]Q!0]9!0]\"%0]!*`]!0`]!6`]!<P]\"BP]\"HP]!P@]\"V0]\""
	"\\0]!``Q!`^Q!`]1\"`[U\"`YY!`X9\"`V=!`T]!`S!!`QA!`Q!!`Q!\"`Q!\"`Q%!`Q%\""
	"";
