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

static char *mona =
	"A)\"-=8V,B*&=AJ\"<:H-_@)67@)V8@)F<AYV<>I24>(Z-B)R2?Y*/B)R:A)J7?I:9"
	"?Y:/?Y2.@9>4BYB=?HZ\"?(^6?9.?@9*-A9Z:?YJ@B)N@A9J<A)V@?I23>YB=@)^C"
	">9.1B)R:>H^1<XB*?Y26@I>9>8R'>Y.6BZ:L>I.9@).8B:\"FB)R<@9:8C*2GDZ>I"
	"?Y.+G:ZIA)N0B)V5BJ\"5BZ.D>9*->XZ,B9Z:@)B7AI:5?Y64B9J5CY^5AIJ2EZF:"
	"?Y*/A9F1BYR3A).+CI^6DJ&=D8R1;V5M7%5>D):7B(J(?(N-@IJ9>8R*>9*.C)V6"
	"BJ\"5;X)_@)&*@Y.'D:6EBIJ9@IB7BJ&HE:NHC9Z5C:\">DZ>EB9J+A):+D*.>BJ.F"
	"AYJ5@96A>I&*E*NBE:NHDZ><BYR3B9B:?Y*/B960AI6-D*:ECJ2@A9F9>8V-FJFC"
	"@Y>/DJ.:AYF:C9F.DZ\"7FI*054%94D%@1C582#5A1S!;<6IZAI6/B)F4CZ*=B*&="
	"E*JFD:2?A9B6AY..>HJ(E*>DBZ&@>I\"-A9J6BYZ<BZ\"8BY^=GJFB@)..D:2BCZ>F"
	"A)R;?IRGAIF4@9J6C:FKE::=@X^$>HJ(C)N7D:\"<DYZ9F*FBD::>D:.6B9V=C9Z7"
	"B9N.GK\"EBIZ4C9F$5CY+8DQ8:%!?43U9/RU3*R1/+\"145T!;)A]6=6IRAYV<BY^7"
	"EZ>EC9J2CZ2<@8^/BJ\"?>9&4=X^0C:\";DZ6:BYJ4H[\"GFJRAAI>(CIV5G[.QBZ&="
	"AY2=C)ZAEK*TEZVJK</\"DZB@EJJJEZ>=F*.>L+VTG:NMI;*GJ[BPIK*ME::?G[\"G"
	"GK\"SFZZV<FIIG8)PN:%^T+>7MIQZK)%S;E%B2#A40S1:)R!5)B%:'AI,%Q)5BHZ."
	"A*\"3E+2TA9V<CZ*GCZ*=G[2VE:ZSEZNKFJFAH*^ICIJ-FJ&2C)F1G*>BGZRAG*^M"
	"@XV.F*>IFJJHD*:CEZRHFJFCD9R4H*VEEZ*3HJVEI+.MH*VEH:ZFHZ^DI+&HJ[6K"
	"G[2ZF)^96T5=RK&2XLBH[=\"IV\\\"4S*R$EG5K;E1A3CM:,\"9:,2EC)2!;&QQ1'Q9:"
	"C9NED*.JBJ*EDZBBG[\"GI+2RH;2QH[.IJKFUFZRED:\":BIN6H:RGEZ:>HZ^DH*^K"
	"GZBDKKNREZ6DEJZ?GK.MK+RPI+2RFZF;GJN@H[\"HJ;.IG*NCFZRGL<&_J+>QFJZP"
	"F:*J1SABB7!JX\\>@XL.EX,\":X<.2XL:8O)MWD'1@<5=;1CMD3#EG*2-@*B9D$A)/"
	"&AA8D:6;DZ>?CZ6AF*FBFZJDE*VIH;\"HHJRJH[\"HI;:OK+.MDIZ1G:B9FJ:9J+O\""
	"=X*%EJN9G;:RF*JMJ;2EH+*UF:RQKKVWI[2IJ[BPG*N7I;2NI+>TI;*IE:><H+6Q"
	"BX%Y/RU6BW)OU+>6Y\\6>[LNDX<2=T;*%N)IYGH!GA&EA23=>*R-5)R!D'QU=&QQ5"
	"'AQ:<HR:C)>0B)R:DZ2?E*BHCZ6AI*^JH:V@H;\"JK+RRJ;2LH*J@GJB<G*>7KKV_"
	"=X\".G+*<H*VBFJVR?).<J+>[FJFKJKJNJ+:FJ[:OF*FDFZB@LL7#J+2IIK*EL,*W"
	"4S)=0C18G'QNZ<VGXL*:W\\&<S;\"1X,&6Q:>$LI5WEGIE8DI;*!M2,\"=7(1U;&1I<"
	"'B!::X\"\"D)B\"C9J2>Y>7G*^L:9\".G+&KI[2KG:N=J;6JJ[.DJ;\"GGJJ=E::=J;BP"
	"3%9P>G]Z7'\"*=X\"&AY:<CIJ7AX^#DY^0=XN)G*NGL;VZJ;RYL+VUML.PR-#\"LKFF"
	"23%6.\"E?JH]]O)AUS*R$T[62O)E\\JXEMQ*>)MIA_J(M^7D1>.2Q@*R5D'1Q?*\")?"
	"&1A=25QL3&5Z9WQ`9X*48H*0;)&8CJ2CIK.HKK>CLKJDK[VMFJ2:FJ>?DZ*F?YRK"
	".CQC66%W676+561V>(6.DYRB?I\"3>(*#<8F,7'F*@XR0IKFVJK6NO<2]L;RMD9^?"
	"3CMI.2QAD&]EB&)XB6=VV;N*<E=GBVIT9T=59E%A8D=;;%%E.2=8(QE6'AMA,\"EM"
	"&!A70E)R5G!^26=N7(*.8(2;:HN3B9F7LKFHMKZEO,B[N<\"QJ;2EDY^<CZ*@AIVL"
	".T%T2U1R8W2/7W:'=H6+?(>*:W1\\:76$8F]^7FMZ;X*);8J7LL7#IJ^WG;*N?HR5"
	"5#1:33IS;$YS<D]B:$A@I81R>UMGDFUD6T)8<%-N9TUI>5YF1C!@*!]9,#!Y%QE3"
	"'!I:7FR%4FB!2%YW6GZ/6WU`8H>:<(20KK:=J*V:L+NLI+&FI:N0F)^8?I:7J\\+)"
	"2TZ\"561`9WV6=HV>4G\"):G)`97)[55QW6W*!76EX569`6VN!?G=`8'6'CZ&6AH&&"
	"0BM8/BA:S[63W;N>R:I_R*AZO:\"!RZ^!W\\&<U;:(RZF$;T]=-B5;,RIJ&!E:(\"EC"
	"(AQ9/4UG.E%Q2%]P:H24.5AU4&Z)7WR-F*6<H*J@J+:FGJB@DYN%EJ*A?H^7BJ&G"
	"1TMY5V:\"96J(5G\"00&!X:G5V7&AU8FU_66MZ6VY]6&R%1E)I;&I^9'2$?8F67UUK"
	".\"%6-RA>O9]^TK\"4V+N4VKF9R*F,X;^2[LVAU[&)NYAY;5%H)1Q2*\")A&1=5%Q=4"
	"'QY90$]O8GJ325MP2FA_/5]Y87R62&A]BIZ>HJ>4G*\"3J:^DFZ6CAY>5B)J?DJ&G"
	"6%U^;'>)4U]V466!56^)76F\"9WF(2%YV36!P25]W1%-Q6&AX7E]^66.'35AT7%9Q"
	"4#!>-BABN)5^V+J?U+:3S:^6OZ&&RZF$QJ)^T*^+K(QV6T1A)!Q/.#!J+\"=H(2)A"
	")2EI76)`:W>$7G)\\>)&7?I2@?)6;;HJ6?IF?DI^7CIZ<C8^-BY*,B).8C96@AI*A"
	"5EN&7&%`14IU6F^/4VE_7W&(3%MO:7J-5VI\\5V=]97\",0U-I4%9M4%U\\35)Y13MA"
	".Q]8)A%3=E-PRZF%SZJ,PZ2'=51>T*Z)QZ>-JHIZAVIM3C9;+2!4(1E32$1`\"A!/"
	")BQG+C%E/4QV1E)Y2%I]3F:+.%E[06)`97>,6GZ+;X>0:XB/9'B46VV02E][8WB6"
	".3]P2E6$04AS0T]T6&B\"3E9N9&J#5&5`8W6\"35AM;WZ45%AT3EEV2E=V/DML4TMS"
	".\"1:,AY>5C=AN99_V[J0V;R;GX)]PZ:(M)-`E'EOB6UM3C99+B55+R-A%Q53%A=."
	"%1I;2$1U0U-U4F:(1%M^.U-V+T=L4FF,26E_-%A\\6'>28WR/9'J20%-T4V1_;'N7"
	"-CQO.#UF,3ID04IJ36%[5%]\\8&5Y5&.!2UIZ7FB$5%YX4%5L2U)M8FB+7V6&*B-0"
	"6S9B0B9@-R%1L8R\"IX!XP9IXD&QLA69MN9J&D7ELAFAI2#1:.2U>+25?(\"!?/CUW"
	"(R9H(1U10U)X1EY[0EN\"1V&!-U!O.$UK3&6$3U]W:'.%87%_7&^.05-Z56&&=8\"?"
	"1$Q\\45!N3%I`55IY7&&\"9V^'96^)25%I25-K1E%N0$MG0E)T7FR'5%YZ5%]R4$EK"
	"1\"=>0\"=@.\"9AIGY_O9]\\SJ^2FGYRGX%VG7]T?V)G:$QC2#9?,2A>/SMV*B5@'\")="
	"$A59+RM?5%1Y<H\"91UMU569`-$9=3V:'2F*%2VB)3F)^25EY15Y^4&2&3%Q\\67\"0"
	".#YO2E)Z24]R1$EJ1DQQ4%5L6%EV-#E81U)G/4)@67*)8W5`3V)T5F5Y8F]^:EMW"
	"+2!50C%F-!Y02SMHJX=XU;:8OIV+LI:\"@65E9DE:6T)9.BY?+R!8*B-:&QA0)\")3"
	"-#9R.S=I24-F0UAL9'.)2F-Z7V^'2F1^.UMS-4UR4&1^26%\\5&N,<(2F66B(4&>("
	"+S)F1$9V24MS-C]I-D%P4%U\\0$5L4%)W1$EG6V2\"5F.\"5V6(6V6)1%)N:'&#23I:"
	"339E6SEJ32Q8031I.S%7K(EVLI*\"AFIG8D=;4SI05SY=,RE<-\"A9+B=<*21?'Q=1"
	"(!]9.#%F.C1C6VR)5%QR;WN087>#46)U0%IZ0EQ^-$ML2&\"#5&N.3F2*1%A^9G6="
	",S5O.3QH56-_*#M<+#YA56%V55V\"4%U\\1E5S56=\\:7F/;'V8=G^/;X*2>HZ8@(V?"
	".B9:-1]13SEH)!A7,R9;.\"I>6T=M4D)H5$-L13I=3S]B2SQ:3#M>.2Q9,\"MF'QY9"
	"$A=/(B-<%B!>.E)U56.&-E!T1V:#2U^!,D!C4V\"#1%1W2%>!6'>28GN22F)_3V:'"
	"/CYS+CAN15)U/$AO,3]K5UYY3UQ_;7^4<8.84V=`:'^@4%YY;H*>;7J,7VUY86E]"
	"3#MN/B=633)F,\"15-2Y9,2I7GH=XCW9S;UAA=5YEAW%U?F9E=F!D53Q:+!]3(1Q3"
	"(\"%:)\"5>(B)A,D%I6W*#:WI^7FY^;H\"+1E]V7'**:72&97)Y8VQ^6&)\\8&V0?GV+"
	".$)T6&&)87:616&(7GN<=XNE;W>%7UA?>X&<8UUF9W.,6E%Q1T!3;WB&>X.74E!D"
	"/2YF+AU3/BA0/C5E.\"U87$USKY2\"N:.*K92!J8]UG8-KI(QIGH1N:4Q)3C1D02]>"
	".B]:+2E=)R5C&!I6,S9@,4!>04E?<GN+-3Y>EHICC(*!@'M^=&YM='!]7F5`7EQ`"
	"";

static char *creeper =
	"4C]04C]00RI-0BE-0BE-3S)33C!23C!23C)33S-33S-33S-33S133S134#M/4#M/"
	"4#M/4#M/4#M/4#M/3T=33T=33T=33T=33T=33T=34$=443Q/43Q/43Q/43Q/43Q/"
	"43Q/43Q/43Q/43Q/4#144#144#=543E643E643E61S!/1S!/1S!/44I644I64D!1"
	"4C]04C]00RI-0BE-0BE-3S)33C!23C!23C)33S-33S-33S-33S133S134#M/4#M/"
	"4#M/4#M/4#M/4#M/3T=33T=33T=33T=33T=33T=34$=443Q/43Q/43Q/43Q/43Q/"
	"43Q/43Q/43Q/43Q/4#144#144#=543E643E643E61S!/1S!/1S!/44I644I64D!1"
	"0BE-0BE-LKS8>7:0>7:0@X\"2!%4'!%4'!$S^!E(#!E(#!4K`!4W`!4W`!$P$!%,%"
	"!%,%!4H#!$P$!$P$!D\\#!%`#!%`#!&@&!&D)!&D)3*H<QNHJQNHJIM<GF=0HF=0H"
	"F-,EC\\`GC\\`GK=\\IL^0JL^0JM.8IO^8EO^8EE,P#W.<\"W.<\"W.8#V\\S.V\\S.1S!/"
	"4#=54#=5N</;=GB0=GB0AH.3!'<,!'<,!'P.!(,.!(,.!'@1!FH+!FH+!V4+!F@-"
	"!F@-!H$0!'D4!'D4!'D42I\\;2I\\;E,`<M>$FM>$F@LD?(ZX;(ZX;-ITC0*(B0*(B"
	"U/$NON<LON<L@,TCFM8DFM8DP.DGM.$@M.$@V_,?W.<(W.<(Y.X/V\\_2V\\_212U."
	"4#=54#=5N</;=GB0=GB0AH.3!'<,!'<,!'P.!(,.!(,.!'@1!FH+!FH+!V4+!F@-"
	"!F@-!H$0!'D4!'D4!'D42I\\;2I\\;E,`<M>$FM>$F@LD?(ZX;(ZX;-ITC0*(B0*(B"
	"U/$NON<LON<L@,TCFM8DFM8DP.DGM.$@M.$@V_,?W.<(W.<(Y.X/V\\_2V\\_212U."
	"4#954#95O,+=?WV1?WV1?'B(!(H0!(H0!9$2(9@4(9@4I]0=T^D@T^D@L]L@A<(:"
	"A<(:%)@:%YP:%YP:.:$:O=`EO=`EVO4PP^<EP^<EI=PDF=HBF=HBB-0CC](FC](F"
	"IMPJN.@LN.@LRO$NW?<PW?<PKN$FM.(CM.(CW?(7WND*WND*X^X1W=;?W=;?4#=5"
	"3SQ33SQ3N;_6B(:<B(:<>W>'+)84+)84$I(2(YH8(YH8\"I85!9<6!9<6!9,75JX?"
	"5JX?9+H=7KL<7KL<6[L?6+,A6+,A<+XDD]$ID]$ID](GJ-W=J-W=%[E04,.\"4,.\""
	"H=?>U^44U^44A^VR?MZJ?MZJ4:**V_8OV_8OU.T9X^`4X^`4X.L.V]/?V]/?4C]0"
	"3SQ33SQ3N;_6B(:<B(:<>W>'+)84+)84$I(2(YH8(YH8\"I85!9<6!9<6!9,75JX?"
	"5JX?9+H=7KL<7KL<6[L?6+,A6+,A<+XDD]$ID]$ID](GJ-W=J-W=%[E04,.\"4,.\""
	"H=?>U^44U^44A^VR?MZJ?MZJ4:**V_8OV_8OU.T9X^`4X^`4X.L.V]/?V]/?4C]0"
	"4#E.4#E.O<7;@'R3@'R3A'V.(9H5(9H5!I843*T93*T93*L77+497+495K092K(7"
	"2K(73;098;LA8;LA:,$B:L$B:L$BDL`H?<DB?<DB?<DD+:-G+:-G8]6:1\\-V1\\-V"
	"<MFF4:**4:**=.R>9LR49LR4U^44D-<LD-<LRN\\AW^P0W^P0XNL/VM;FVM;F4C10"
	"3T933T93O<38?7J,?7J,=7&!,)`3,)`3!)P/,:@2,:@21JX31*P11*P1\":(-$JH1"
	"$JH10:X:7+D>7+D>1;4<L-TBL-TBV?,KQNLGQNLGG=<<2-)V2-)V(V18/&IT/&IT"
	"F.3+6:J46:J4(EU9/&IT/&ITW^P<?,PG?,PGSNP4X_$3X_$3W^D*Y.+VY.+V4C10"
	"3T933T93O<38?7J,?7J,=7&!,)`3,)`3!)P/,:@2,:@21JX31*P11*P1\":(-$JH1"
	"$JH10:X:7+D>7+D>1;4<L-TBL-TBV?,KQNLGQNLGG=<<2-)V2-)V(V18/&IT/&IT"
	"F.3+6:J46:J4(EU9/&IT/&ITW^P<?,PG?,PGSNP4X_$3X_$3W^D*Y.+VY.+V4C10"
	"3T933T93N<'7=WB+=WB+<&EP+*81+*81%J,4$*43$*430*P4!)`2!)`2'J\\0HM@:"
	"HM@:?<L9WO0IWO0IF=49!'S>!'S>2*?XC,H(C,H(2:'L4-M]4-M](EU9!!!!!!!!"
	":=Z52<1Z2<1Z!!!!&TI5&TI5?-VHS>XIS>XI:[CKX>P-X>P-XNP+X=WMX=WM3T=3"
	"4#M/4#M/N,/?=W6)=W6)@W^.3J443J442Z\\4!9<,!9<,,J475K,85K,8<,02AL\\9"
	"AL\\9;<(:I=@=I=@=L^$DL^$BL^$BON4F?\\@#?\\@#7JSUCN'#CN'#:,67F.3+F.3+"
	"'UM5'UM5'UM5R.0!3)R&3)R&7N.+6Z[S6Z[SL=X9V^<\"V^<\"X>P-V]/AV]/A4$=4"
	"4#M/4#M/N,/?=W6)=W6)@W^.3J443J442Z\\4!9<,!9<,,J475K,85K,8<,02AL\\9"
	"AL\\9;<(:I=@=I=@=L^$DL^$BL^$BON4F?\\@#?\\@#7JSUCN'#CN'#:,67F.3+F.3+"
	"'UM5'UM5'UM5R.0!3)R&3)R&7N.+6Z[S6Z[SL=X9V^<\"V^<\"X>P-V]/AV]/A4$=4"
	"4#I/4#I/M\\7@>WR1>WR1=6]\\!7?]!7?]!'_Z!(0'!(0'!8D+%IH.%IH.!8H&!(\\)"
	"!(\\)/J060J@<0J@<5+(9H=,@H=,@=\\,6G,\\6G,\\6DL\\6IN#;IN#;5*.//&IT/&IT"
	"!!!!!!!!!!!!(V59:.23:.23P>/Z!'7X!'7XW/,BV>/_V>/_W^H.V<_7V<_743U/"
	"4#I/4#I/M<#<;V^&;V^&>'!^!(H-!(H-.IL1#I0-#I0-FL,!E[#-E[#-A):M67RG"
	"67RG-&F@GLC[GLC[!&SH!%78!%78/9D,\"X8!\"X8!!$GNQ?+[Q?+[:[&G!!!!!!!!"
	"!!!!!!!!!!!!!!!!8\\V18\\V15:F.(87V(87V<[4/V.'_V.'_V^4$U\\W7U\\W743U/"
	"4#I/4#I/M<#<;V^&;V^&>'!^!(H-!(H-.IL1#I0-#I0-FL,!E[#-E[#-A):M67RG"
	"67RG-&F@GLC[GLC[!&SH!%78!%78/9D,\"X8!\"X8!!$GNQ?+[Q?+[:[&G!!!!!!!!"
	"!!!!!!!!!!!!!!!!8\\V18\\V15:F.(87V(87V<[4/V.'_V.'_V^4$U\\W7U\\W743U/"
	"3T533T53I[#\":&E^:&E^@WN'!&S<!&S<!%B\\!7#C!7#C<)*V7W*!7W*!!#-0PM;Z"
	"PM;Z1W\"/16>!16>!!1AC!!I7!!I7!2R4!$BC!$BC!E.N:.23:.23A^VR&TI5&TI5"
	"E^+%LN#ILN#I'UM5/)QT/)QT;-R8!G'\\!G'\\!([VU-[`U-[`UN$\"U<O5U<O543Q/"
	"3SY33SY3J:^`;6I^;6I^>G-BQM#LQM#LP]3^R=C`R=C`6XQZ99.(99.(H+_#992-"
	"992-5)*(D+*CD+*CR-;YT=[]T=[]R]KZVND+VND+T-W^U-_[U-_[S]KYU.H7U.H7"
	"L<;BN=(\"N=(\"W>X=W.H<W.H<TMSXT]W_T]W_TN$,UN0.UN0.T^$#RK_$RK_$4C-/"
	"3SY33SY3J:^`;6I^;6I^>G-BQM#LQM#LP]3^R=C`R=C`6XQZ99.(99.(H+_#992-"
	"992-5)*(D+*CD+*CR-;YT=[]T=[]R]KZVND+VND+T-W^U-_[U-_[S]KYU.H7U.H7"
	"L<;BN=(\"N=(\"W>X=W.H<W.H<TMSXT]W_T]W_TN$,UN0.UN0.T^$#RK_$RK_$4C-/"
	"3SM33SM3IJF[L;\"_L;\"_OKS0L[+!L[+!L+*_LK;#LK;#N+?&N+?%N+?%MK:]M[6_"
	"M[6_MK&VOKC#OKC#Q+[)MZZPMZZPNK\"RO+.UO+.UO[2QPKBXPKBXQ;RXQKNZQKNZ"
	"PKBZR,''R,''P[J\\S<;/S<;/Q+W#P[NYP[NYR+W\"R<#\"R<#\"PKBZR;[%R;[%3S13"
	"3S133S13I[#.JK#+JK#+K:[#I:2UI:2UK*_#LK/(LK/(J*BSK:RZK:RZOK[5L;+#"
	"L;+#M;.]L:RRL:RRM;*ZOKO%OKO%KZNKN[;)N[;)L:BJO;:]O;:]O;:\\O+>\\O+>\\"
	"O;K\"PK[+PK[+O+>\\P;O(P;O(NK2]P[W*P[W*O+C'Q+W-Q+W-N[._O;;&O;;&4#]4"
	"3S133S13I[#.JK#+JK#+K:[#I:2UI:2UK*_#LK/(LK/(J*BSK:RZK:RZOK[5L;+#"
	"L;+#M;.]L:RRL:RRM;*ZOKO%OKO%KZNKN[;)N[;)L:BJO;:]O;:]O;:\\O+>\\O+>\\"
	"O;K\"PK[+PK[+O+>\\P;O(P;O(NK2]P[W*P[W*O+C'Q+W-Q+W-N[._O;;&O;;&4#]4"
	"4C]04C]00RI-0BE-0BE-3S)33C!23C!23C)33S-33S-33S-33S133S134#M/4#M/"
	"4#M/4#M/4#M/4#M/3T=33T=33T=33T=33T=33T=34$=443Q/43Q/43Q/43Q/43Q/"
	"43Q/43Q/43Q/43Q/4#144#144#=543E643E643E61S!/1S!/1S!/44I644I64D!1"
	"";



