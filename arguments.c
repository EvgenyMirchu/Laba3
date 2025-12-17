#include "arguments.h"


Mode* initialize_Mode_struct()
{   
    Mode* new_mode = malloc(sizeof(Mode));
    if (new_mode == NULL) return NULL;
    
    new_mode->curr_mode = NULL;
    new_mode->amount_of_generatoins = 0;  
    new_mode->in_data = NULL;
    new_mode->out_data = NULL;
    new_mode->sorting_type = NULL;
    new_mode->generation_status = '1';
    new_mode->in_status = '0';
    new_mode->out_status = '0';
    new_mode->type_status = '0';
    return new_mode;
}

int str_is_digit(char * str)
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        // isdigit - это функция для проверки символа на совпадение с цифрой
        if (!isdigit((unsigned char)str[i])) return 0; 
    }
    return 1;
}

Mode* define_mode(Mode* mode, int arg_c, char* arg_v[])
{
    if (mode == NULL)
    {
        puts("Ошибка при выделении памяти.");
        return NULL;
    } 

    if (arg_c == 1)
    {
        puts("Помощь:\n");
        return NULL;
    }

    for (int i = 1; i < arg_c; ++i)
    {
        if (i == 1)
        {
            if (strcmp(arg_v[i], "--generate") == 0 || strcmp(arg_v[i], "-g") == 0) mode->curr_mode = "generate";
            else if (strcmp(arg_v[i], "--sort") == 0 || strcmp(arg_v[i], "-s") == 0) mode->curr_mode = "sort";
            else if (strcmp(arg_v[i], "--print") == 0 || strcmp(arg_v[i], "-p") == 0) mode->curr_mode = "print";

            else
                {
                    puts("Ошибка при считывании данных: введен несуществующий мод работы");
                    return NULL;
                }
        }

        else
        {
            if ((mode->curr_mode != NULL) && ( strcmp(arg_v[i], "--generate") == 0 \
            || strcmp(arg_v[i], "-g") == 0 || strcmp(arg_v[i], "--sort") == 0 || strcmp(arg_v[i], "-s") == 0 \
            || strcmp(arg_v[i], "--print") == 0 || strcmp(arg_v[i], "-p") == 0 ))
            {
                puts("Ошибка при считывании данных: Нельзя выбрать больше 1 мода работы.");
                return NULL;
            }

            if (strcmp(mode->curr_mode, "generate") == 0) // Флаг генерации
            {
                if (mode->generation_status == '1')
                {
                    if (str_is_digit(arg_v[i]) && strlen(arg_v[i]) <= 2) // максимум двузначное число число 
                    {
                        short N = (short) atoi(arg_v[i]); // преобразование числа в
                        if (MIN_GENERATIONS <= N && N <= MAX_GENERATIONS) mode->amount_of_generatoins = N;
                        else
                        {
                            printf("Ошибка при считывании данных: число генераций можно брать из множества целых чисел от %d до %d.", MIN_GENERATIONS, MAX_GENERATIONS);
                            return NULL;
                        }
                    }

                    else
                    {
                        puts("Ошибка при считывании данных: агрумент генерации не целое число.");
                        return NULL;
                    }
                    mode->generation_status = '2';
                }

                else if (mode->generation_status == '2')
                {
                    if (strcmp(arg_v[i], "--out") == 0 || strcmp(arg_v[i], "-o") == 0)
                    {
                        mode->out_status = '1';
                    }

                    else if (strcmp(arg_v[i], "output.csv") == 0 && mode->out_status == '1')
                    {
                        mode->out_data = arg_v[i];
                        mode->out_status = '2';
                    }

                    else
                    {
                        puts("Ошибка при считывании данных: нарушение работы во время считывания переменных.");
                    }
                }
            }
                

            if (strcmp(mode->curr_mode, "sort") == 0) // Флаг сортировки
            {   
                if (strcmp(arg_v[i], "--out") == 0 || strcmp(arg_v[i], "-o") == 0)
                {
                    mode->out_status = '1';
                }
                else if (strcmp(arg_v[i], "--in") == 0 || strcmp(arg_v[i], "-i") == 0)
                {
                    mode->in_status = '1';
                }
                else if (strcmp(arg_v[i], "--type") == 0 || strcmp(arg_v[i], "-t") == 0)
                {
                    mode->type_status = '1';
                }

                else if (mode->out_status == '1')
                {
                    mode->out_data = arg_v[i];
                    mode->out_status = '2';
                }
                else if (mode->in_status == '1')
                {
                    mode->in_data = arg_v[i];
                    mode->in_status = '2';
                }
                else if (mode->type_status == '1')
                {
                    if (strcmp(arg_v[i], "desc") == 0 || strcmp(arg_v[i], "D") == 0 \
                        || strcmp(arg_v[i], "asc") == 0 || strcmp(arg_v[i], "A") == 0)
                    {
                        mode->sorting_type = arg_v[i];
                        mode->type_status = '2';
                    }
                    else
                    {
                        puts("Ошибка при считывании данных: неизвестный аргумент типа сортировки.");
                        return NULL;
                    }
                }
                else
                {
                    puts("Ошибка при считывании данных: неизвестный аргумент.");
                    return NULL;
                }
            }


            if (strcmp(mode->curr_mode, "print") == 0)
            {
                if (strcmp(arg_v[i], "--out") == 0 || strcmp(arg_v[i], "-o") == 0)
                {
                    mode->out_status = '1';
                }
                else if (strcmp(arg_v[i], "--in") == 0 || strcmp(arg_v[i], "-i") == 0)
                {
                    mode->in_status = '1';
                }

                else if (mode->out_status == '1')
                {
                    mode->out_data = arg_v[i];
                    mode->out_status = '2';
                }
                else if (mode->in_status == '1')
                {
                    mode->in_data = arg_v[i];
                    mode->in_status = '2';
                }
                else
                {
                    puts("Ошибка при считывании данных: неизвестный аргумент.");
                    return NULL;
                }
            }   
        }
    }

    //Проверка 
    
    if (strcmp(mode->curr_mode, "generate") == 0)
    {
        if (mode->amount_of_generatoins == 0)
        {
            puts("Ошибка при считывании данных: не указано число генераций");
            return NULL;
        }
    }
    else if (strcmp(mode->curr_mode, "sort") == 0)
    {
        if (mode->in_status == '1')
        {
            puts("Ошибка: для режима sort не указан входной файл");
            return NULL;
        }
        if (mode->out_status == '1')
        {
            puts("Ошибка: для режима sort не указан выходной файл");
            return NULL;
        }
        if (mode->type_status == '1')
        {
            puts("Ошибка: для режима sort не указан тип сортировки");
            return NULL;
        }
    }
    else if (strcmp(mode->curr_mode, "print") == 0)
    {
        if (mode->in_status == '1')
        {
            puts("Ошибка: для режима print не указан входной файл");
            return NULL;
        }
        if (mode->out_status == '1')
        {
            puts("Ошибка: для режима print не указан выходной файл");
            return NULL;
        }
    }
    return mode;
}