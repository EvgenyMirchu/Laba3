#include "input-output.h"


void export_to_csv(Top *stack, FILE *output) {
    short size = stack_get_size(stack);
    for (short i = 0; i < size; i++) {
        Node *node = stack_get_node(stack, i);
        if (node && node->publication) {
            Publication *p = node->publication;
            fprintf(output, "\"%s\",\"%s\",\"%s\",\"%s\",%hu,%hd,%hd,%d,%hd\n",
                   p->publication_name,
                   p->author_second_name,
                   p->author_initials,
                   p->magazine_name,
                   p->magazine_volume,
                   p->publication_year,
                   p->pages_amount,
                   p->is_in_RSCI,
                   p->citations_amount);
        }
    }
}

Top* import_from_csv(FILE *input) {
    Top *stack = stack_init();
    if (stack == NULL) return NULL;
    
    char line[1024];
    while (fgets(line, 1024, input)) {
        // Удаляем символ новой строки
        line[strcspn(line, "\n")] = 0;
        
        Publication *pub = malloc(sizeof(Publication));
        if (pub == NULL) continue;
        
        char *token;
        char *rest = line;
        
        // Разбираем CSV
        token = strtok_r(rest, ",", &rest);
        if (token[0] == '"') {
            pub->publication_name = strdup(token + 1);
            pub->publication_name[strlen(pub->publication_name) - 1] = '\0';
        } else {
            pub->publication_name = strdup(token);
        }
        
        token = strtok_r(rest, ",", &rest);
        pub->author_second_name = strdup(token[0] == '"' ? token + 1 : token);
        pub->author_second_name[strlen(pub->author_second_name) - (pub->author_second_name[0] == '"' ? 2 : 0)] = '\0';
        
        token = strtok_r(rest, ",", &rest);
        pub->author_initials = strdup(token[0] == '"' ? token + 1 : token);
        pub->author_initials[strlen(pub->author_initials) - (pub->author_initials[0] == '"' ? 2 : 0)] = '\0';
        
        token = strtok_r(rest, ",", &rest);
        pub->magazine_name = strdup(token[0] == '"' ? token + 1 : token);
        pub->magazine_name[strlen(pub->magazine_name) - (pub->magazine_name[0] == '"' ? 2 : 0)] = '\0';
        
        pub->magazine_volume = atoi(strtok_r(rest, ",", &rest));
        pub->publication_year = atoi(strtok_r(rest, ",", &rest));
        pub->pages_amount = atoi(strtok_r(rest, ",", &rest));
        pub->is_in_RSCI = atoi(strtok_r(rest, ",", &rest));
        pub->citations_amount = atoi(strtok_r(rest, ",", &rest));
        
        stack_push_end(stack, pub);
    }
    
    return stack;
}

void print_publication_table(Top *stack, FILE *output) {
    short size = stack_get_size(stack);
    
    fprintf(output, "┌─────┬──────────────────────────────┬────────────────┬──────────┬────────────────────┬──────┬──────┬──────┬──────┬──────────────┐\n");
    fprintf(output, "│ №   │ Название публикации          │ Фамилия автора │ Инициалы │ Журнал             │ Том  │ Год  │ Стр. │ РИНЦ │ Цитирования  │\n");
    fprintf(output, "├─────┼──────────────────────────────┼────────────────┼──────────┼────────────────────┼──────┼──────┼──────┼──────┼──────────────┤\n");
    
    for (short i = 0; i < size; i++) {
        Node *node = stack_get_node(stack, i);
        if (node && node->publication) {
            Publication *p = node->publication;
            
            // Обрезаем длинные строки для таблицы
            char pub_name[27];
            strncpy(pub_name, p->publication_name, 26);
            pub_name[26] = '\0';
            if (strlen(p->publication_name) > 26) {
                pub_name[23] = pub_name[24] = pub_name[25] = '.';
            }
            
            char mag_name[18];
            strncpy(mag_name, p->magazine_name, 17);
            mag_name[17] = '\0';
            if (strlen(p->magazine_name) > 17) {
                mag_name[14] = mag_name[15] = mag_name[16] = '.';
            }
            
            fprintf(output, "│ %3hd │ %-28s │ %-14s │ %-8s │ %-18s │ %4hu │ %4hd │ %4hd │ %4s │ %12hd │\n",
                   i + 1,
                   pub_name,
                   p->author_second_name,
                   p->author_initials,
                   mag_name,
                   p->magazine_volume,
                   p->publication_year,
                   p->pages_amount,
                   p->is_in_RSCI ? "YES" : "NO",
                   p->citations_amount);
        }
    }
    
    fprintf(output, "└─────┴──────────────────────────────┴────────────────┴──────────┴────────────────────┴──────┴──────┴──────┴──────┴──────────────┘\n");
}