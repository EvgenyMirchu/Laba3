#include "arguments.h"
#include "container.h"
#include "gnome_sorting.h"
#include "input-output.h"
#include "struct.h"


int main(int argc, char* argv[]) 
{
    // генератор случайных чисел
    srand(time(NULL));
    
    // 1) Обработка аргументов командной строки
    Mode* mode = initialize_Mode_struct();
    if (!mode) 
    {
        fprintf(stderr, "Error: Failed to initialize mode\n");
        return 1;
    }
    
    mode = define_mode(mode, argc, argv);
    if (!mode) 
    {
        free(mode);
        return 1;
    }
    
    // Проверяем, что режим был установлен
    if (!mode->curr_mode) 
    {
        fprintf(stderr, "Error: No mode specified\n");
        free(mode);
        return 1;
    }
    
    // 2) Создаем стек
    Top *stack = stack_init();
    if (!stack) 
    {
        fprintf(stderr, "Error: Failed to create stack\n");
        free(mode);
        return 1;
    }
    
    // 3) Выполнение выбранного режима
    if (strcmp(mode->curr_mode, "generate") == 0) 
    {
        
        // Генерируем N публикаций
        for (short i = 0; i < mode->amount_of_generatoins; i++) 
        {
            Publication *pub = new_pub();
            if (pub) 
            {
                stack_push_end(stack, pub);
            }
        }
        
        // Сохраняем в файл или выводим на экран
        if (mode->out_status == '2') 
        {
            FILE *out_file = fopen(mode->out_data, "w");
            if (out_file) 
            {
                export_to_csv(stack, out_file);
                fclose(out_file);
                printf("Generated %hd publications to %s\n", 
                       mode->amount_of_generatoins, mode->out_data);
            } 

            else 
            {
                fprintf(stderr, "Error: Cannot open output file\n");
            }
        } 

        else 
        {
            export_to_csv(stack, stdout);
        }
        
    } 

    else if (strcmp(mode->curr_mode, "sort") == 0) // Режим сортировки
    {
        
        // Чтение данных
        FILE *in_file = stdin;
        if (mode->in_status == '2' && mode->in_data) 
        {
            in_file = fopen(mode->in_data, "r");
            if (!in_file) 
            {
                fprintf(stderr, "Error: Cannot open input file %s\n", mode->in_data);
                stack_free(stack);
                free(mode);
                return 1;
            }
        }
        
        // Импортируем данные из CSV
        Top *temp_stack = import_from_csv(in_file);
        if (temp_stack) {
            stack_free(stack); // Освобождаем старый стек
            stack = temp_stack; // Используем новый стек с данными
        } 

        else 
        {
            fprintf(stderr, "Error: Failed to import data\n");
        }
        
        if (in_file != stdin) fclose(in_file);
        
        if (mode->sorting_type) 
        {
            if (strcmp(mode->sorting_type, "desc") == 0 || 
                strcmp(mode->sorting_type, "D") == 0) 
            {
                gnome_sort(stack, -1); // По убыванию
            } 
            
            else 
            {
                gnome_sort(stack, 1); // По возрастанию
            }
        }

        else 
        {
            gnome_sort(stack, 1); // По умолчанию - по возрастанию
        }
        
        // Вывод результатов
        if (mode->out_status == '2' && mode->out_data) 
        {
            FILE *out_file = fopen(mode->out_data, "w");
            if (out_file) 
            {
                export_to_csv(stack, out_file);
                fclose(out_file);
            } 
            else 
            {
                fprintf(stderr, "Error: Cannot open output file\n");
            }
        }


        else 
        {
            export_to_csv(stack, stdout);
        }
        
    }

    else if (strcmp(mode->curr_mode, "print") == 0) // Режим печати таблицы
    {
        
        // Чтение данных
        FILE *in_file = stdin;
        if (mode->in_status == '2' && mode->in_data) 
        {
            in_file = fopen(mode->in_data, "r");
            if (!in_file) 
            {
                fprintf(stderr, "Error: Cannot open input file %s\n", mode->in_data);
                stack_free(stack);
                free(mode);
                return 1;
            }
        }
        
        // Импортируем данные
        Top *temp_stack = import_from_csv(in_file);
        if (temp_stack) 
        {
            stack_free(stack);
            stack = temp_stack;
        } 

        else 
        {
            fprintf(stderr, "Error: Failed to import data\n");
        }
        
        if (in_file != stdin) fclose(in_file);
        
        // Печать таблицы
        if (mode->out_status == '2' && mode->out_data) 
        {
            FILE *out_file = fopen(mode->out_data, "w");
            if (out_file) 
            {
                print_publication_table(stack, out_file);
                fclose(out_file);
            } 

            else 
            {
                fprintf(stderr, "Error: Cannot open output file\n");
            }
        } 

        else 
        {
            print_publication_table(stack, stdout);
        }
    }
    
    // 4) Очистка памяти
    stack_free(stack);
    free(mode);
    
    return 0;
}