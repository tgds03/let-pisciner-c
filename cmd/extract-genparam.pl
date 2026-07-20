#!/usr/bin/perl
use strict;

my $keyword = $ARGV[0];
my $stub = do { local $/; <STDIN> };
my @code;
my $seed = hex(substr($ENV{RANDSEED}, -8));
my $header;

$seed -= 0x100000000 if $seed >= 0x80000000;
$header = "srand($seed);\n";
if ($stub =~ m#/\*\* genparam $keyword\s*( .*)\*/#gs) {
    @code = ($1 =~ m# \* (.*)#g);
    unshift @code, $header;
    print @code;
}