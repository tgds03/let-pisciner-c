sub char {
    if ($_[0] == 0) {
        return '\0';
    } elsif ($_[0] == 7) {
        return '\a';
    } elsif ($_[0] == 8) {
        return '\b';
    } elsif ($_[0] == 9) {
        return '\t';
    } elsif ($_[0] == 10) {
        return '\n';
    } elsif ($_[0] == 11) {
        return '\v';
    } elsif ($_[0] == 12) {
        return '\f';
    } elsif ($_[0] == 13) {
        return '\r';
    } elsif ($_[0] == 34) {
        return '\"';
    } elsif ($_[0] == 39) {
        return "\\'";
    } elsif ($_[0] == 92) {
        return "\\\\";
    } else {
        return chr($_[0]);
    }
}
sub ascii_inline {
    $res = '"';
    for $i (1 .. 127) {
        $res .= char($i);
    }
    $res .= '"';
    return $res;
}
sub printable_inline {
    $res = '"';
    for $i (32 .. 126) {
        $res .= char($i);
    }
    $res .= '"';
    return $res;
}
srand($seed);
$, = ' ';
$\ = "\n";