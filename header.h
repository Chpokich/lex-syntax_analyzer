#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 


//typedef struct;
#define s_zero '0' 
#define s_one '1'
#define s_two '2' 
#define s_three '3' 
#define s_four '4' 
#define s_five '5' 
#define s_six '6' 
#define s_seven '7' 
#define s_eight '8' 
#define s_nine '9' 
#define sd 'd'
#define se 'e' 
#define sf 'f' 
#define sh 'h'
#define si 'i' 
#define sl 'l' 
#define so 'o'
#define sr 'r' 
#define sw 'w' 
#define s_open_parenthesis '('
#define s_close_parenthesis ')'
#define s_semicolon ';'
#define s_equals '=' 
#define s_comma ','
#define s_dot '.' 
#define s_brace_opening '{'
#define s_brace_closing '}'
#define s_next_line '\n' 
#define s_end_string '\0'
#define s_space 32 
//abab baab 

 enum states{
//  state_end_string, 
  state_initial,   
  state_end_file, 
  state_digit, 
  state_next_line,
  state_open_parenthesis,
  state_semicolon,
  state_close_parenthesis,
  state_open_brace,
  state_close_brace,
  state_digit_space,
  state_digit_dot, 
  state_digit_dot_digit, 
  state_d,
  state_do, 
  state_w, 
  state_wh, 
  state_whi,
  state_whil, 
  state_while,
  state_final,
  state_f,
  state_fo,
  state_for
};

extern enum states table[100][250];

void write_to_output_file(); 

void get_token(); 

void syntax_analysis(enum states *state_arr_p);

#endif // HEADER_H
