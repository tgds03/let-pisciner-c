#ifndef ARITHM_PARSER_H
#define ARITHM_PARSER_H

struct ParseEnv {
    int iter;
} parse_env;

int arithm_parse(const char *str);

#endif