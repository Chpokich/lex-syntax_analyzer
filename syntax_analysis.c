#include "header.h"
#include <stdio.h>
//extern enum states; 
//
void proc_digit(enum states* s);
void proc_digit_dot_digit(enum states* s);
void proc_do(enum states* s);
void proc_for(enum states* s);
void proc_while(enum states* s); 
void proc_open_parenthesis(enum states* s);
void proc_close_parenthesis(enum states* s); 
void proc_close_brace(enum states* s);
void proc_open_brace(enum states* s); 
void proc_semicolon(enum states* s); 
void proc_next_line(enum states* s); 
int proc_end_file(enum states* s); 

static int counter = 1;
static int counter_error = 0;
static int counter_open_brace = 0;
static int counter_open_paranthesis = 0; 

int proc_end_file(enum states* s)
{
  puts("end_file");
  return 0;
}
void proc_close_brace(enum states* s)
{
  
    s++;
    if(counter_open_brace == 0){
    printf("line %d - BRACE QUANTITY ERROR\n", counter);
    counter_error++;
    syntax_analysis(s);

  }else{
    counter_open_brace--; 
    puts("state_close_brace");

  switch (*s) {
    case state_next_line:
      syntax_analysis(s);
      break;
    case state_semicolon:
      proc_semicolon(s);
      break;
    case state_end_file:
      proc_end_file(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_close_brace)\n", counter);
      syntax_analysis(s);
      break;  
  }
  }
}

void proc_semicolon(enum states* s)
{
  puts("state_semicolon"); s++;

  switch (*s) {
    case state_next_line:
      syntax_analysis(s);
      break;
    case state_end_file:
      proc_end_file(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_semicolon)\n", counter);
      syntax_analysis(s);
      break;
  }
}

void proc_next_line(enum states* s)
{
  counter++;
  puts("state_next_line");
  s++;
  switch (*s) {
    case state_while:
      proc_while(s);
      break;
    case state_for:
      proc_for(s); 
      break;
    case state_do:
      proc_do(s);
      break;
    case state_digit:
      proc_digit(s);
      break;
    case state_digit_dot_digit:
      proc_digit_dot_digit(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_next_line)\n", counter);
      syntax_analysis(s);
  }
}

void proc_digit_dot_digit(enum states* s)
{

  puts("state_digit_dot_digit");
  s++;

  switch (*s) {
    case state_next_line:
      syntax_analysis(s);
      break;
    case state_close_parenthesis:
      proc_close_parenthesis(s);
      break;
    case state_semicolon:
      proc_semicolon(s);
      break;
    case state_close_brace:
      proc_close_brace(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_digit_dot_digit)\n", counter); 
      syntax_analysis(s);
  }
}

void proc_digit(enum states* s)
{
  
  puts("state_digit");
  s++;

  switch (*s) {
    case state_next_line:
      syntax_analysis(s);
      break;
    case state_close_parenthesis:
      proc_close_parenthesis(s);
      break;
    case state_semicolon:
      proc_semicolon(s);
      break;
    case state_close_brace:
      proc_close_brace(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_digit)\n", counter); 
      syntax_analysis(s);
  }

}

void proc_close_parenthesis(enum states* s)
{
  puts("state_close_parenthesis");
  s++;
  counter_open_paranthesis--; 
  switch (*s) {
    case state_next_line:
      syntax_analysis(s);
      break;
    case state_semicolon:
      proc_semicolon(s);
      break;
    case state_open_brace:
      proc_open_brace(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_close_parenthesis)\n", counter);
      syntax_analysis(s);
      break;  
  }

}
  
void proc_open_brace(enum states* s)
{
  s++; 
  puts("open_brace");
  counter_open_brace++;

  switch (*s) {
    case state_next_line:
      syntax_analysis(s);
      break;
    case state_for:
      proc_for(s);
      break;
    case state_while:
      proc_while(s);
      break; 
    case state_do:
      proc_do(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_open_brace)\n", counter);
      syntax_analysis(s);
      break; 
  }

}

void proc_open_parenthesis(enum states* s)
{
  s += 1;
  puts("open_parenthesis");

  switch (*s) {
    case state_digit:
      proc_digit(s);
      break;
    case state_digit_dot_digit:
      proc_digit_dot_digit(s);
      break;
    case state_close_parenthesis:
      proc_close_parenthesis(s);
      break;
    default:
      s++;
      counter_error++;
      printf("line %d - SYNTAX ERROR (proc_open_parenthesis)\n", counter);
      syntax_analysis(s);
      break; 
  }

  counter_open_paranthesis++; 
}

void proc_for(enum states* s)
{
    puts("state_for");
    s += 1;

    switch (*s) {
      case state_open_parenthesis: 
        proc_open_parenthesis(s);
        break;
      default:
        s++;
        counter_error++;
        printf("line %d - SYNTAX ERROR (proc_for)\n", counter);
        syntax_analysis(s);
        break; 
    } 
}

void proc_do(enum states* s)
{
     puts("state_do");
     s += 1;

    switch (*s) {
      case state_open_brace: 
        proc_open_parenthesis(s);
        break;
      default:
        s++;
        counter_error++;
        printf("line %d - SYNTAX ERROR (proc_do)\n", counter);
        syntax_analysis(s);
        break; 
    }
    
}

void proc_while(enum states* s)
{
    puts("state_while");
    s += 1;

    switch (*s) {
      case state_open_parenthesis: 
        proc_open_parenthesis(s);
        break;
      default:
         counter_error++;
         s++;
        printf("line %d - SYNTAX ERROR (proc_while)\n", counter);
        syntax_analysis(s);
        break; 
    }
        //if(*s != state_
}


void syntax_analysis(enum states* s)
{

    switch (*s) {
      case state_for:
        proc_for(s);
        break;
      case state_while:
        proc_while(s);
        break;
      case state_do:
        proc_do(s);
        break;
      case state_digit:
        proc_digit(s);
        break;
      case state_digit_dot_digit:
        proc_digit_dot_digit(s);
        break;
      case state_next_line:
        s++;
        counter++; 
        //proc_next_line(s);
        syntax_analysis(s);
        break;
      case state_close_brace:
        if(counter_open_brace > 0){
          proc_close_brace(s);
        }else{
          s++;
          counter_open_brace++;
          printf("line %d - SYNTAX ERROR (syntax_analysis state_close_brace)\n", counter); 
          counter_error++;
          syntax_analysis(s);
        }
        break;
      case state_initial:
        if(counter_error == 0)
          puts("sucsess compile!");
        else
         printf("\n%d errors occured!\n", counter_error);
        proc_end_file(s);
        break; 
      case state_end_file:
        if(counter_error == 0)
          puts("sucsess compile!");
        else
         printf("\n%d errors occured!\n", counter_error);
        proc_end_file(s);
        break; 
      default:
        s++; 
        printf("line %d - SYNTAX ERROR (syntax_analysis default)\n", counter); 
        counter_error++;
        syntax_analysis(s);
        break; 
    }
    //s += 1; 
    //syntax_analysis(s);
} 
