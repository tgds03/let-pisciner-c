#!/usr/bin/perl
use strict;

open my $headerfile, '<', 'cmd/genparam-header.pl' or die "Can not open genparam-header.pl: $!";
local $/;
my $header = <$headerfile>;
close $headerfile;

my $keyword = $ARGV[0];
my $stub = do { local $/; <STDIN> };
my $code;
my $seed = hex(substr($ENV{RANDSEED}, -8));
$header =~ s#\$seed#$seed#s;

$seed -= 0x100000000 if $seed >= 0x80000000;
if ($stub =~ m#/\*\* genparam $keyword\s*( .*?)\*/#gs) {
    $code = $1;
    $code =~ s#^ \* (.*)$#\1#gm;
    $code = $header . "\n" . $code;
    print $code;
}