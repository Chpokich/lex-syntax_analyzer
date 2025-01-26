#include "header.h"

void write_to_output_file(int* row_counter, char* str, int* file_is_open_before, int* row_counter_prev_state){
  FILE *file_output; 
  char *file_name_output = "output.txt"; 

if(*file_is_open_before){
  if((file_output = fopen(file_name_output, "a")) == NULL){
    puts("file does not exist!");
    exit(1);
  }
  if(*row_counter_prev_state != *row_counter){
    fprintf(file_output, "\n"); 
    *row_counter_prev_state = *row_counter; 
    //fprintf(file_output, "counter = %d\t couter_prev = %d\n", *row_counter, *row_counter_prev_state); 
  }
  fprintf(file_output, "%s", str); 
  fclose(file_output);
}else{
  file_output = fopen(file_name_output, "w");
  fprintf(file_output, "%s\n", str);
  fclose(file_output);
}
  
}


