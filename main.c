
#include "header.h"
#include <stdio.h>

  enum states table[100][250] = {
  [state_initial][s_open_parenthesis] = state_open_parenthesis, 
  [state_initial][s_close_parenthesis] = state_close_parenthesis, 
  [state_initial][s_semicolon] = state_semicolon, 
  [state_initial][s_equals] = state_final, 
  [state_initial][s_comma] = state_final,
  [state_initial][s_next_line] = state_next_line,
  [state_initial][s_space] = state_initial,
  [state_initial][s_brace_opening] = state_open_brace, 
  [state_initial][s_brace_closing] = state_close_brace,

  //[state_next_line][s_end_string] = state_end_string,

  [state_initial][s_zero] = state_digit,
  [state_initial][s_one] = state_digit,
  [state_initial][s_two] = state_digit,
  [state_initial][s_three] = state_digit,
  [state_initial][s_four] = state_digit,
  [state_initial][s_five] = state_digit,
  [state_initial][s_six] = state_digit, 
  [state_initial][s_seven] = state_digit, 
  [state_initial][s_eight] = state_digit,
  [state_initial][s_nine] = state_digit,

  [state_next_line][s_zero] = state_digit,
  [state_next_line][s_one] = state_digit,
  [state_next_line][s_two] = state_digit,
  [state_next_line][s_three] = state_digit,
  [state_next_line][s_four] = state_digit,
  [state_next_line][s_five] = state_digit,
  [state_next_line][s_six] = state_digit, 
  [state_next_line][s_seven] = state_digit, 
  [state_next_line][s_eight] = state_digit,
  [state_next_line][s_nine] = state_digit,

  [state_next_line][sw] = state_w,
  [state_next_line][sf] = state_f,
  [state_next_line][sd] = state_d,

  [state_open_parenthesis][s_zero] = state_digit,
  [state_open_parenthesis][s_one] = state_digit,
  [state_open_parenthesis][s_two] = state_digit,
  [state_open_parenthesis][s_three] = state_digit,
  [state_open_parenthesis][s_four] = state_digit,
  [state_open_parenthesis][s_five] = state_digit,
  [state_open_parenthesis][s_six] = state_digit,
  [state_open_parenthesis][s_seven] = state_digit,
  [state_open_parenthesis][s_eight] = state_digit,
  [state_open_parenthesis][s_nine] = state_digit,

  [state_digit][s_zero] = state_digit,
  [state_digit][s_one] = state_digit,
  [state_digit][s_two] = state_digit,
  [state_digit][s_three] = state_digit, 
  [state_digit][s_four] = state_digit,
  [state_digit][s_five] = state_digit,
  [state_digit][s_six] = state_digit,
  [state_digit][s_seven] = state_digit, 
  [state_digit][s_eight] = state_digit,
  [state_digit][s_nine] = state_digit,

  [state_digit][s_close_parenthesis] = state_close_parenthesis,
  [state_digit_dot_digit][s_close_parenthesis] = state_close_parenthesis,
  [state_close_parenthesis][s_semicolon] = state_semicolon,
  [state_close_parenthesis][s_next_line] = state_next_line,
  [state_close_brace][s_next_line] = state_next_line,
  [state_digit][s_next_line] = state_next_line,
  [state_digit_dot_digit][s_next_line] = state_next_line,
  [state_for][s_next_line] = state_next_line,
  [state_while][s_next_line] = state_next_line,
  [state_semicolon][s_next_line] = state_next_line, 
  [state_semicolon][s_space] = state_initial,
  
  [state_digit][s_dot] = state_digit_dot,
  [state_digit_dot][s_zero] = state_digit_dot_digit,
  [state_digit_dot][s_one] = state_digit_dot_digit, 
  [state_digit_dot][s_two] = state_digit_dot_digit, 
  [state_digit_dot][s_three] = state_digit_dot_digit, 
  [state_digit_dot][s_four] = state_digit_dot_digit,
  [state_digit_dot][s_five] = state_digit_dot_digit,
  [state_digit_dot][s_six] = state_digit_dot_digit,
  [state_digit_dot][s_seven] = state_digit_dot_digit,
  [state_digit_dot][s_eight] = state_digit_dot_digit,
  [state_digit_dot][s_nine] = state_digit_dot_digit,
   
  [state_digit_dot_digit][s_zero] = state_digit_dot_digit,
  [state_digit_dot_digit][s_one] = state_digit_dot_digit, 
  [state_digit_dot_digit][s_two] = state_digit_dot_digit, 
  [state_digit_dot_digit][s_three] = state_digit_dot_digit, 
  [state_digit_dot_digit][s_four] = state_digit_dot_digit,
  [state_digit_dot_digit][s_five] = state_digit_dot_digit,
  [state_digit_dot_digit][s_six] = state_digit_dot_digit,
  [state_digit_dot_digit][s_seven] = state_digit_dot_digit,
  [state_digit_dot_digit][s_eight] = state_digit_dot_digit,
  [state_digit_dot_digit][s_nine] = state_digit_dot_digit,

  [state_digit_dot_digit][s_semicolon] = state_semicolon,
  [state_digit_dot_digit][s_open_parenthesis] = state_open_parenthesis,
  [state_digit_dot_digit][s_brace_closing] = state_close_brace,
  [state_digit_dot_digit][s_space] = state_final,
  //[state_digit_dot_digit][s_next_line] = state_next_line,
  [state_digit][s_space] = state_final, 

  [state_initial][sd] = state_d, 
  [state_d][so] = state_do,
  [state_do][s_brace_opening] = state_open_brace,
  [state_close_parenthesis] = state_open_brace, 
  [state_open_brace][s_next_line] = state_next_line, 
  [state_next_line][s_space] = state_initial, 
  [state_next_line][s_brace_closing] = state_close_brace, 
  [state_next_line][s_next_line] = state_next_line, 
  [state_close_brace][s_space] = state_final,
  [state_open_brace][s_brace_closing] = state_close_brace,

  [state_do][s_space] = state_final,
 // [state_do][s_brace_opening] = state_final,

  [state_initial][sw] = state_w, 
  [state_w][sh] = state_wh, 
  [state_wh][si] = state_whi, 
  [state_whi][sl] = state_whil,
  [state_whil][se] = state_while,
  [state_while][s_open_parenthesis] = state_open_parenthesis,
  [state_open_parenthesis][s_close_parenthesis] = state_close_parenthesis,
  [state_close_parenthesis][s_brace_opening] = state_open_brace,
  [state_while][s_space] = state_final,

  [state_initial][sf] = state_f,
  [state_f][so] = state_fo,
  [state_fo][sr] = state_for,
  [state_for][s_open_parenthesis] = state_open_parenthesis,
  [state_for][s_space] = state_final
};

//Массив для синтаксического анализатора
enum states state_arr[100];
int row_counter = 1;

int get_output_data(enum states* s_arr)
{
  
  switch (*s_arr) {
case state_for:
  printf("token = for %-5s row = %-10d\n","",row_counter);
  break;
case state_while:
  printf("token = while %-5s row = %-10d\n","",row_counter);
  break;
case state_do:
  printf("token = do %-5s row = %-10d\n","",row_counter);
  break;
case state_semicolon:
  printf("token = ; %-5s row = %-10d\n","",row_counter);
  break;
 case state_open_parenthesis:
  printf("token = ( %-5s row = %-10d\n","",row_counter);
  break;
 case state_close_parenthesis:
  printf("token = ) %-5s row = %-10d\n","",row_counter);
  break;
 case state_open_brace:
  printf("token = { %-5s row = %-10d\n","",row_counter);
  break;
 case state_close_brace:
  printf("token = } %-5s row = %-10d\n","",row_counter);
  break;
 case state_digit:
  printf("token = NUM %-5s row = %-10d\n","",row_counter);
  break;
case state_digit_dot_digit:
  printf("token = FLOAT %-5s row = %-10d\n","",row_counter);
  break;
case state_next_line:
  row_counter++; 
  break;
case state_initial:
  row_counter = 1;
  return 0;
  break;
case state_end_file: 
  return 0;
  default:
  break;

  } 
  s_arr += 1; 
  get_output_data(s_arr);
  return 0; 
}

void get_token()
{
  int file_is_open_before = 0; 
  FILE *file_input;
  char ch;
  int row_counter = 1;
  char str[30]; 
  enum states current = state_initial; 
  enum states previous = state_initial; 
  int state_arr_counter = 0; 
  char *file_name = "input.txt";

  if((file_input = fopen(file_name,"r"))== NULL){
      puts("file does not exist!"); 
      exit(1);
      }
  int i = 0;

  int row_counter_prev_state = 0;


  while((ch = fgetc(file_input)) != EOF){
    if((current == state_next_line|| current == state_close_brace || current == state_close_parenthesis) && (previous == state_digit || previous == state_digit_dot_digit)){
      state_arr[state_arr_counter] = previous;
      state_arr_counter++;
    }
    //Условие проходит только готовый токен
    if(current == state_final || current == state_for || current == state_while || current == state_do || current == state_open_brace || current == state_open_parenthesis || current == state_close_brace || current == state_close_parenthesis || current == state_semicolon || current == state_next_line){
      state_arr[state_arr_counter] = current;
      state_arr_counter++;
      if(current == state_final)
        current = state_initial;

      //Вывод в консоль номер строки и токен
     // printf("row = %-5d\t token = %-10s\n",row_counter, str);

      //Вывод номера строки и токена в другой файл
      /*write_to_output_file(&row_counter, str, 
      &file_is_open_before, &row_counter_prev_state);*/

      memset(str, 0, sizeof(str));
      file_is_open_before = 1; 
      i = 0; 
    }
    
    //Если текущее состояние равно начальносу, 
    //то строка хранящая токен очищается
   /* if(current == state_initial){
      i = 0; 
    }*/

    if(ch == '\n')
      row_counter++; 

    if((current != state_do) && (current != state_while) &&
        (current != state_for)){ 
      str[i] = ch; 
    }else{
      memset(str, 0, sizeof(str));
      str[i] = ch;
    }
    /*printf("Current state = %d\n",  
        current);  */
    if(current != state_final)
      previous = current;

    current = table[current][ch];
    i++;

  }
  state_arr_counter++; 
  state_arr[state_arr_counter] = state_end_file;
  state_arr_counter = 0; 
  fclose(file_input);
}

int main()
{
  get_token();
  int a = 5;
  int* i = &a;
  
  puts("\n\n");
  get_output_data(state_arr);
  puts("\n\n");
 //enum state* state_arr_p = state_arr;
 syntax_analysis(state_arr); 
  return 0;
}
