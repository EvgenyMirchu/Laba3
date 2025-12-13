#include "generation.h"


static const char* FIRST_NAMES[] = {
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

static const char* INITIALS[] = {
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

static const char* JOURNALS[] = {
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

static const char* TITLE_WORDS[] = {
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

static const char* TITLE_ADJECTIVES[] = {
    "Novel", "Efficient", "Robust", "Scalable", "Adaptive",
    "Distributed", "Parallel", "Interactive", "Intelligent", "Secure",
    "Advanced", "Innovative", "Reliable", "Flexible", "Autonomous",
    "Collaborative", "Cognitive", "Dynamic", "Hierarchical", "Modular",
    "Multimodal", "Real-time", "Self-organizing", "Ubiquitous", "Versatile",
    "Biologically-inspired", "Cloud-based", "Edge-computing", "Federated", "Quantum",
    "Explainable", "Interpretable", "Privacy-preserving", "Energy-efficient", "High-performance",
    "Low-latency", "Memory-efficient", "Fault-tolerant", "Self-healing", "Context-aware"
};

static const char* RESEARCH_DOMAINS[] = {
    "Machine Learning", "Deep Learning", "Computer Vision", "Natural Language Processing",
    "Robotics", "Cybersecurity", "Bioinformatics", "Quantum Computing",
    "Internet of Things", "Blockchain", "Augmented Reality", "Cloud Computing",
    "Edge Computing", "High-Performance Computing", "Wireless Networks",
    "Biomedical Engineering", "Renewable Energy", "Climate Modeling",
    "Financial Analytics", "Social Network Analysis", "Digital Humanities",
    "Precision Agriculture", "Smart Cities", "Autonomous Vehicles"
};

static const char* METHODOLOGY_WORDS[] = {
    "using", "based on", "via", "through", "employing",
    "leveraging", "incorporating", "combining", "extending", "modifying"
};

