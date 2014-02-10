#! /usr/bin/octave -qf

rc = load("-ascii", "recurring-cycles.dat");
rc = rc';


plot(rc, "@12");
print("recurring-cycles.png");
