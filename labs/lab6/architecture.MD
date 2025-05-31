Lab6App/
│
├── main.cpp                  → App entry (UI / CLI logic)
├── controller/
│   └── TokenizerController.h / .cpp  → Facade for managing token flow
│
├── tokenizer/
│   ├── TokenizerBase.h       → Abstract Strategy class
│   ├── SimpleTokenizer.h/.cpp → Concrete Strategy (current behavior)
│   └── TokenizerFactory.h/.cpp → Factory that returns TokenizerBase*
│
├── model/
│   └── Token.h               → Fragment or Token structure
│
├── utils/
│   └── InputHandler.h/.cpp   → Handles file/interactive input (optional)
