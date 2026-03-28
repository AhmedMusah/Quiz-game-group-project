#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define ROW 2
#define COLUMN 150

// HISTORY - EASY
typedef struct
{
    const char *question;
    char answer;
} TriviaQuestion;

// HISTORY - EASY
TriviaQuestion easy_hist[8] = {
    {"Who discovered gravity with an apple?\nA. Galileo\nB. Newton\nC. Einstein\nD. Tesla", 'B'},
    {"Who is the Father of Computing?\nA. Charles Babbage\nB. Alan Turing\nC. Bill Gates\nD. Steve Jobs", 'A'},
    {"Who invented the lightbulb?\nA. Alexander Bell\nB. Thomas Edison\nC. Henry Ford\nD. James Watt", 'B'},
    {"Who developed the theory of relativity?\nA. Stephen Hawking\nB. Albert Einstein\nC. Marie Curie\nD. Isaac Newton", 'B'},
    {"Who discovered Penicillin?\nA. Alexander Fleming\nB. Louis Pasteur\nC. Gregor Mendel\nD. Charles Darwin", 'A'},
    {"First man to walk on the moon?\nA. Neil Armstrong\nB. Buzz Aldrin\nC. Yuri Gagarin\nD. John Glenn", 'A'},
    {"Who studied evolution in the Galapagos?\nA. Jean Lamarck\nB. Gregor Mendel\nC. Charles Darwin\nD. Carl Linnaeus", 'C'},
    {"Who invented the telephone?\nA. Samuel Morse\nB. Alexander Graham Bell\nC. Nikola Tesla\nD. Eli Whitney", 'B'}};

// HISTORY - MEDIUM
TriviaQuestion med_hist[8] = {
    {"Who won Nobel Prizes in two different sciences?\nA. Marie Curie\nB. Linus Pauling\nC. John Bardeen\nD. Frederick Sanger", 'A'},
    {"Who developed the first polio vaccine?\nA. Albert Sabin\nB. Edward Jenner\nC. Jonas Salk\nD. Robert Koch", 'C'},
    {"Which ancient Greek shouted 'Eureka' in a bath?\nA. Pythagoras\nB. Archimedes\nC. Euclid\nD. Aristotle", 'B'},
    {"Lead scientist of the Manhattan Project?\nA. J. Robert Oppenheimer\nB. Enrico Fermi\nC. Niels Bohr\nD. Richard Feynman", 'A'},
    {"Who discovered the laws of planetary motion?\nA. Tycho Brahe\nB. Johannes Kepler\nC. Edmond Halley\nD. Giovanni Cassini", 'B'},
    {"Who discovered the structure of DNA with Crick?\nA. Rosalind Franklin\nB. James Watson\nC. Jane Goodall\nD. Rachel Carson", 'B'},
    {"Who invented the AC electrical system?\nA. Thomas Edison\nB. Nikola Tesla\nC. Michael Faraday\nD. Benjamin Franklin", 'B'},
    {"Who is the Father of Optics?\nA. Ibn al-Haytham\nB. Johannes Kepler\nC. Christiaan Huygens\nD. Max Planck", 'A'}};

// HISTORY - HARD
TriviaQuestion hard_hist[8] = {
    {"Who wrote the first computer algorithm?\nA. Ada Lovelace\nB. Grace Hopper\nC. Alan Turing\nD. Blaise Pascal", 'A'},
    {"Who found the Uncertainty Principle?\nA. Werner Heisenberg\nB. Erwin Schrodinger\nC. Max Planck\nD. Paul Dirac", 'A'},
    {"Who proposed the Big Bang theory?\nA. Edwin Hubble\nB. Stephen Hawking\nC. Georges Lemaitre\nD. Carl Sagan", 'C'},
    {"Who invented the World Wide Web in 1989?\nA. Vint Cerf\nB. Tim Berners-Lee\nC. Marc Andreessen\nD. Bill Gates", 'B'},
    {"Who created the Periodic Table?\nA. Antoine Lavoisier\nB. John Dalton\nC. Dmitri Mendeleev\nD. Robert Boyle", 'C'},
    {"First woman in space?\nA. Sally Ride\nB. Valentina Tereshkova\nC. Judith Resnik\nD. Mae Jemison", 'B'},
    {"Who discovered blood circulation?\nA. William Harvey\nB. Andreas Vesalius\nC. Galen\nD. Hippocrates", 'A'},
    {"Who discovered Radioactivity?\nA. Henri Becquerel\nB. Ernest Rutherford\nC. JJ Thomson\nD. James Chadwick", 'A'}};

// SCIENCE - EASY
TriviaQuestion easy_sci[8] = {
    {"The Red Planet?\nA. Venus\nB. Mars\nC. Jupiter\nD. Saturn", 'B'},
    {"Symbol for Gold?\nA. Gd\nB. Ag\nC. Au\nD. Fe", 'C'},
    {"Organ that pumps blood?\nA. Lungs\nB. Brain\nC. Heart\nD. Liver", 'C'},
    {"Boiling point of water (C)?\nA. 0\nB. 50\nC. 100\nD. 212", 'C'},
    {"Gas humans exhale?\nA. Oxygen\nB. Nitrogen\nC. Carbon Dioxide\nD. Helium", 'C'},
    {"Closest star to Earth?\nA. Proxima Centauri\nB. The Sun\nC. Sirius\nD. Polaris", 'B'},
    {"Center of an atom?\nA. Electron\nB. Proton\nC. Nucleus\nD. Neutron", 'C'},
    {"Adult human teeth count?\nA. 28\nB. 30\nC. 32\nD. 34", 'C'}};

// SCIENCE - MEDIUM
TriviaQuestion med_sci[8] = {
    {"Most abundant gas in air?\nA. Oxygen\nB. Nitrogen\nC. Argon\nD. CO2", 'B'},
    {"Speed of sound (m/s)?\nA. 343\nB. 299,792\nC. 150\nD. 1000", 'A'},
    {"Bones in adult human body?\nA. 204\nB. 206\nC. 210\nD. 212", 'B'},
    {"Powerhouse of the cell?\nA. Nucleus\nB. Mitochondria\nC. Ribosome\nD. Vacuole", 'B'},
    {"Atomic number of Carbon?\nA. 4\nB. 12\nC. 6\nD. 8", 'C'},
    {"Vitamin from the sun?\nA. Vit A\nB. Vit B\nC. Vit C\nD. Vit D", 'D'},
    {"pH of pure water?\nA. 5\nB. 6\nC. 7\nD. 8", 'C'},
    {"Planet with most moons?\nA. Jupiter\nB. Saturn\nC. Neptune\nD. Mars", 'B'}};

// SCIENCE - HARD
TriviaQuestion hard_sci[8] = {
    {"Absolute zero in Celsius?\nA. -273.15\nB. 0\nC. -100\nD. -32", 'A'},
    {"Heaviest natural element?\nA. Uranium\nB. Plutonium\nC. Lead\nD. Osmium", 'A'},
    {"Negatively charged particle?\nA. Proton\nB. Neutron\nC. Electron\nD. Photon", 'C'},
    {"Main component of natural gas?\nA. Ethane\nB. Methane\nC. Propane\nD. Butane", 'B'},
    {"Largest internal organ?\nA. Heart\nB. Brain\nC. Liver\nD. Lungs", 'C'},
    {"Planet rotating on its side?\nA. Uranus\nB. Neptune\nC. Venus\nD. Jupiter", 'A'},
    {"Escape velocity of Earth?\nA. 11.2 km/s\nB. 5.5 km/s\nC. 25 km/s\nD. 40 km/h", 'A'},
    {"Unit of magnetic flux?\nA. Tesla\nB. Weber\nC. Gauss\nD. Henry", 'B'}};

// MATH - EASY
TriviaQuestion easy_math[8] = {
    {"12 x 12 = ?\nA. 124\nB. 144\nC. 164\nD. 142", 'B'},
    {"Square root of 81?\nA. 7\nB. 9\nC. 8\nD. 10", 'B'},
    {"25% of 100?\nA. 10\nB. 25\nC. 50\nD. 20", 'B'},
    {"Solve: x + 5 = 12\nA. 5\nB. 7\nC. 8\nD. 17", 'B'},
    {"Degrees in a right angle?\nA. 45\nB. 90\nC. 180\nD. 360", 'B'},
    {"Which is a prime number?\nA. 4\nB. 11\nC. 9\nD. 15", 'B'},
    {"Sides in an octagon?\nA. 6\nB. 7\nC. 8\nD. 10", 'C'},
    {"100 divided by 4?\nA. 20\nB. 25\nC. 30\nD. 40", 'B'}};

// MATH - MEDIUM
TriviaQuestion med_math[8] = {
    {"Value of Pi (2 decimal)?\nA. 3.12\nB. 3.14\nC. 3.16\nD. 3.18", 'B'},
    {"Solve: 2x - 4 = 10\nA. 3\nB. 5\nC. 7\nD. 14", 'C'},
    {"2 to the power of 5?\nA. 16\nB. 24\nC. 32\nD. 64", 'C'},
    {"Area of a circle formula?\nA. 2*pi*r\nB. pi*r^2\nC. pi*d\nD. l*w", 'B'},
    {"15 x 6 = ?\nA. 80\nB. 90\nC. 100\nD. 110", 'B'},
    {"Degrees in a triangle?\nA. 90\nB. 180\nC. 270\nD. 360", 'B'},
    {"Square root of 225?\nA. 13\nB. 14\nC. 15\nD. 16", 'C'},
    {"Solve: 10 + 5 * 2\nA. 30\nB. 20\nC. 25\nD. 15", 'B'}};

// MATH - HARD
TriviaQuestion hard_math[8] = {
    {"Derivative of x^3?\nA. x^2\nB. 3x^2\nC. 2x^3\nD. 3x", 'B'},
    {"Log(100) base 10?\nA. 1\nB. 2\nC. 3\nD. 10", 'B'},
    {"Sum of angles in a hexagon?\nA. 360\nB. 540\nC. 720\nD. 900", 'C'},
    {"Value of Golden Ratio?\nA. 1.414\nB. 1.618\nC. 2.718\nD. 3.141", 'B'},
    {"Solve: log2(8) = x\nA. 2\nB. 3\nC. 4\nD. 8", 'B'},
    {"Who co-developed Calculus?\nA. Leibniz\nB. Euler\nC. Gauss\nD. Pascal", 'A'},
    {"Sine of 90 degrees?\nA. 0\nB. 0.5\nC. 1\nD. -1", 'C'},
    {"Zeros in a billion?\nA. 6\nB. 7\nC. 8\nD. 9", 'D'}};

// ENGLISH - EASY
TriviaQuestion easy_eng[8] = {
    {"Synonym for 'Huge'?\nA. Tiny\nB. Large\nC. Fast\nD. Cold", 'B'},
    {"Opposite of 'Hard'?\nA. Difficult\nB. Soft\nC. Firm\nD. Solid", 'B'},
    {"Which is a vowel?\nA. B\nB. E\nC. D\nD. F", 'B'},
    {"Past tense of 'Run'?\nA. Runned\nB. Ran\nC. Running\nD. Runs", 'B'},
    {"Plural of 'Child'?\nA. Childs\nB. Children\nC. Childrens\nD. Childes", 'B'},
    {"Identify the noun:\nA. Blue\nB. Bird\nC. Flies\nD. Quickly", 'B'},
    {"Correct spelling:\nA. Receive\nB. Recieve\nC. Receve\nD. Riceive", 'A'},
    {"Punctuation for a question?\nA. Period\nB. Question Mark\nC. Comma\nD. Colon", 'B'}};

// ENGLISH - MEDIUM
TriviaQuestion med_eng[8] = {
    {"Which is an adjective?\nA. Quickly\nB. Quick\nC. Run\nD. Happiness", 'B'},
    {"Group of lions called?\nA. Pack\nB. Herd\nC. Pride\nD. Flock", 'C'},
    {"Plural of 'Mouse'?\nA. Mouses\nB. Mice\nC. Mices\nD. Meese", 'B'},
    {"Identify the adverb:\nA. He\nB. Sang\nC. Loudly\nD. Song", 'C'},
    {"Antonym for 'Generous'?\nA. Kind\nB. Selfish\nC. Happy\nD. Rich", 'B'},
    {"Choose the correct spelling:\nA. Occasion\nB. Ocasion\nC. Occassion\nD. Ocassion", 'A'},
    {"Which is a conjunction?\nA. And\nB. Big\nC. Very\nD. Under", 'A'},
    {"A person who writes books:\nA. Author\nB. Editor\nC. Publisher\nD. Reader", 'A'}};

// ENGLISH - HARD
TriviaQuestion hard_eng[8] = {
    {"What is 'Onomatopoeia'?\nA. Comparison\nB. Word sounding like its meaning\nC. A repeat\nD. A lie", 'B'},
    {"Example of a Metaphor:\nA. Life is a highway\nB. Cold as ice\nC. Busy as a bee\nD. Red like a rose", 'A'},
    {"Main character of a story:\nA. Antagonist\nB. Protagonist\nC. Narrator\nD. Author", 'B'},
    {"Which word is a 'Palindrome'?\nA. Level\nB. Hello\nC. World\nD. Happy", 'A'},
    {"What does 'Omni-' mean?\nA. One\nB. Many\nC. All\nD. None", 'C'},
    {"Identify the 'Oxymoron':\nA. Deafening silence\nB. Bright light\nC. Running fast\nD. Cold ice", 'A'},
    {"Who wrote 'Hamlet'?\nA. Dickens\nB. Shakespeare\nC. Hemingway\nD. Austen", 'B'},
    {"A 14-line poem:\nA. Haiku\nB. Sonnet\nC. Limerick\nD. Epic", 'B'}};

int check_answer(char, char);
int quiz_user(char, char, int);
void result_prompt(int, int);

int main()
{
    int total = 0, number_of_questions;
    char option, subject, difficulty;
    bool used_questions[ROW];

    srand(time(NULL));

    for (;;)
    {
        printf("Select a subject to be quizzed on : \nE - English\nM - Mathematics\nS - Science\nH - History\n");
        subject = getchar();
        getchar();
        printf("Select difficulty :\nE - Easy\nM - Medium\nH - Hard\n");
        difficulty = getchar();
        getchar();
        printf("How many questions do you want to answer (The maximum is 8 ):");
        scanf("%d", &number_of_questions);
        if (number_of_questions > 8)
        {
            printf("Your input exceeds the maximum.\n");
        }
        else
        {
            total = quiz_user(subject, difficulty, number_of_questions);
            result_prompt(total, number_of_questions);
            option = getchar();

            if (option == 'n' || option == 'N')
            {
                break;
            }
        }
    }
}

void result_prompt(int t, int r)
{
    printf("\nYou got %d out of %d questions correct.", t, r);
    printf("\nDo you want to take another quiz ? (y for yes\nnfor no): ");
}
int check_answer(char a, char b)
{
    int add = 0;
    if (toupper(a) == b)
    {
        printf("Correct");
        add++;
    }
    else
    {
        printf("Wrong");
    }
    return add;
}
int quiz_user(char c, char d, int n)
{
    int total_score = 0, i;
    char option, user_answer, subject, difficulty;
    bool used_questions[ROW];

    if (toupper(c) == 'E' && toupper(d) == 'E') // easy english questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, easy_eng[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, easy_eng_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'E' && toupper(d) == 'M') // medium English questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, med_eng[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, med_eng_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'E' && toupper(d) == 'H') // hard English questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, hard_eng[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, hard_eng_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'M' && toupper(d) == 'E') // Easy Math questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, easy_math[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, easy_math_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'M' && toupper(d) == 'M') // medium math questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, med_math[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, med_math_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'M' && toupper(d) == 'H') // hard math questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, hard_math[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, hard_math_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'S' && toupper(d) == 'E') // easy science questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, easy_sci[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, easy_sci_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'S' && toupper(d) == 'M') // medium math questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, med_sci[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, med_sci_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'S' && toupper(d) == 'H') // hard science questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, hard_sci[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, hard_sci_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'H' && toupper(d) == 'E') // easy history questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, easy_hist[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, easy_hist_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'H' && toupper(d) == 'M') // medium history questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, med_hist[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, med_hist_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    if (toupper(c) == 'H' && toupper(d) == 'H') // hard history questions
    {
        for (int j = 1; j < n + 1;)
        {
            i = rand() % n;
            if (!used_questions[i])
            {
                printf("\n%d. %s\nYour answer: ", j, hard_hist[i]);
                user_answer = getchar();
                getchar();
                total_score += check_answer(user_answer, hard_hist_ans[i]);
                used_questions[i] = true;
                j++;
            }
        }
    }
    return total_score;
}