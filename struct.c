#include "struct.h"


int compare(Publication *a, Publication *b) //Компаратор. Если 1, то a > b; если 0, то a = b; если -1, то a < b  
{
    int compare_pub_name = strcmp(a->publication_name, b->publication_name);
    if (compare_pub_name == 0)
    {
        int compare_sec_name = strcmp(a->author_second_name, b->author_second_name);
        if (compare_sec_name == 0)
        {
            int compare_initials = strcmp(a->author_initials, b->author_initials);
            if (compare_initials == 0)
            {
                int compare_mag_name = strcmp(a->magazine_name, b->magazine_name);
                if (compare_mag_name == 0)
                { 
                    if (a->magazine_volume == b->magazine_volume)
                    {   
                        if (a->publication_year == b->publication_year)
                        {
                            if (a->is_in_RSCI == b->is_in_RSCI)
                            {
                                if (a->citations_amount == b->citations_amount) return 0;
                                if (a->citations_amount > b->citations_amount) return 1;
                                return -1;
                            }
                            
                            if (a->is_in_RSCI == true) return 1;
                            return -1;
                        }

                        if (a->publication_year > b->publication_year) return 1;
                        return -1;
                    }

                    if (a->magazine_volume > b->magazine_volume) return 1;
                    return -1;
                }
                if (compare_mag_name > 0) return 1;
                return -1;
            }
            if (compare_initials > 0) return 1;
            return -1;
        }

        if (compare_sec_name > 0) return 1;
        return -1;
    }

    if (compare_pub_name > 0) return 1;
    return -1;
}


//_____________________________________________________________________________
//_____________________________________________________________________________
//_______________________Дальше_идет_генерация_________________________________
//_____________________________________________________________________________
//_____________________________________________________________________________



const char* FIRST_NAMES[] = {
    "Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Smirnov",
    "Popov", "Lebedev", "Kozlov", "Novikov", "Morozov",
    "Volkov", "Pavlov", "Semenov", "Golubev", "Vinogradov",
    "Fedorov", "Mikhailov", "Nikolaev", "Orlov", "Romanov",
    "Sergeev", "Tarasov", "Ushakov", "Filippov", "Yakovlev",
    "Borisov", "Grigoriev", "Danilov", "Egorov", "Zakharov",
    "Karpov", "Lazarev", "Maksimov", "Nikitin", "Osipov",
    "Pavlovsky", "Rybakov", "Saveliev", "Timofeev", "Fadeev",
    "Kharitonov", "Chernov", "Shcherbakov", "Yudin", "Zhukov",
    "Klimov", "Melnikov", "Polyakov", "Sorokin", "Titov"
};

const char* INITIALS[] = {
    "A.A.", "B.B.", "C.C.", "D.D.", "E.E.",
    "F.F.", "G.G.", "H.H.", "I.I.", "J.J.",
    "K.K.", "L.L.", "M.M.", "N.N.", "O.O.",
    "P.P.", "Q.Q.", "R.R.", "S.S.", "T.T.",
    "U.U.", "V.V.", "W.W.", "X.X.", "Y.Y.",
    "Z.Z.", "A.B.", "C.D.", "E.F.", "G.H.",
    "I.J.", "K.L.", "M.N.", "O.P.", "Q.R.",
    "S.T.", "U.V.", "W.X.", "Y.Z.", "A.I.",
    "B.V.", "D.K.", "E.P.", "S.M.", "V.A."
};

const char* JOURNALS[] = {
    "Science", "Nature", "Journal of Physics", "Computer Science Review",
    "Mathematics Today", "Engineering Journal", "Biology Letters",
    "Chemistry World", "AI Research", "Data Science Quarterly",
    "Physical Review", "IEEE Transactions", "ACM Computing Surveys",
    "Cell", "The Lancet", "PNAS", "Physical Review Letters",
    "Journal of the American Chemical Society", "Advanced Materials",
    "Nature Communications", "Science Advances", "IEEE Access",
    "Computer Networks", "Bioinformatics", "Neural Networks",
    "Journal of Machine Learning Research", "International Journal of Computer Vision",
    "Journal of Climate", "Astrophysical Journal", "Nuclear Physics B",
    "Materials Science and Engineering", "Environmental Science & Technology",
    "Journal of Economic Literature", "Psychological Review",
    "New England Journal of Medicine", "Chemical Reviews",
    "Nature Methods", "IEEE Software", "ACM Transactions on Graphics"
};

const char* TITLE_WORDS[] = {
    "Research", "Analysis", "Study", "Development", "Application",
    "Model", "System", "Algorithm", "Theory", "Method",
    "Optimization", "Evaluation", "Framework", "Approach", "Solution",
    "Implementation", "Comparison", "Review", "Survey", "Design",
    "Investigation", "Exploration", "Assessment", "Measurement", "Detection",
    "Prediction", "Classification", "Clustering", "Regression", "Simulation",
    "Visualization", "Processing", "Generation", "Extraction", "Recognition",
    "Transformation", "Compression", "Encryption", "Verification", "Validation",
    "Automation", "Integration", "Deployment", "Maintenance", "Monitoring",
    "Forecasting", "Planning", "Scheduling", "Routing", "Allocation"
};

const char* TITLE_ADJECTIVES[] = {
    "Novel", "Efficient", "Robust", "Scalable", "Adaptive",
    "Distributed", "Parallel", "Interactive", "Intelligent", "Secure",
    "Advanced", "Innovative", "Reliable", "Flexible", "Autonomous",
    "Collaborative", "Cognitive", "Dynamic", "Hierarchical", "Modular",
    "Multimodal", "Real-time", "Self-organizing", "Ubiquitous", "Versatile",
    "Biologically-inspired", "Cloud-based", "Edge-computing", "Federated", "Quantum",
    "Explainable", "Interpretable", "Privacy-preserving", "Energy-efficient", "High-performance",
    "Low-latency", "Memory-efficient", "Fault-tolerant", "Self-healing", "Context-aware"
};

const char* RESEARCH_DOMAINS[] = {
    "Machine Learning", "Deep Learning", "Computer Vision", "Natural Language Processing",
    "Robotics", "Cybersecurity", "Bioinformatics", "Quantum Computing",
    "Internet of Things", "Blockchain", "Augmented Reality", "Cloud Computing",
    "Edge Computing", "High-Performance Computing", "Wireless Networks",
    "Biomedical Engineering", "Renewable Energy", "Climate Modeling",
    "Financial Analytics", "Social Network Analysis", "Digital Humanities",
    "Precision Agriculture", "Smart Cities", "Autonomous Vehicles"
};


const char* random_element(const char* array[], int size) 
{
    return array[rand() % size];
}

char* generate_title() 
{
    int words = 3 + rand() % 5; // 3-7 слов
    char* temp = malloc(256 * sizeof(char)); // Выделяем память
    if (temp == NULL) return NULL;
    
    temp[0] = '\0'; // Инициализируем пустой строкой
    int words_generated = 0;
    
    // 40% вероятности начать с прилагательного
    if (rand() % 100 < 40) {
        strncat(temp, random_element(TITLE_ADJECTIVES, 40), 256 - strlen(temp));
        strncat(temp, " ", 511 - strlen(temp));
        words_generated++;
    }
    
    while (words_generated < words) {
        // 30% вероятности добавить исследовательскую область
        if (words_generated > 0 && words_generated < words - 1 && rand() % 100 < 30) {
            strncat(temp, random_element(RESEARCH_DOMAINS, 24), 256 - strlen(temp));
            words_generated += 2;
        } else {
            strncat(temp, random_element(TITLE_WORDS, 50), 256 - strlen(temp));
            words_generated++;
        }
        
        if (words_generated < words) {
            strncat(temp, " ", 511 - strlen(temp));
        }
    }
    
    return temp;
}

Publication* new_pub()
{
    Publication* new = malloc(sizeof(Publication));
    if (new == NULL) return NULL;

    srand(time(NULL));

    new->publication_name = generate_title();
    new->author_second_name = random_element(FIRST_NAMES, sizeof(FIRST_NAMES)/sizeof(FIRST_NAMES[0])); 
    new->author_initials = random_element(INITIALS, sizeof(INITIALS)/sizeof(INITIALS[0]));
    new->magazine_name = random_element(JOURNALS, sizeof(JOURNALS)/sizeof(JOURNALS[0]));

    new->magazine_volume = (unsigned short) (1 + rand() % 150); // 1-150 издание/том
    new->publication_year = (unsigned short) (1991 + rand() % 34); // 1991-2025 год
    new->pages_amount = (short) (3 + rand() % 298); // 3-300 страниц
    if ((rand() % 100) < 65) new->is_in_RSCI = true; // 65% статей в РИНЦ
    else new->is_in_RSCI = false;
    new->citations_amount = (short) (rand() % 5001); // 0-5000 цитирований

    return new;
}

void free_publication(Publication *pub) {
    if (pub) {
        free(pub->publication_name);
        free(pub);
    }
}