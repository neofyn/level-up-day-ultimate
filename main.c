/*
 * Level Up Day - Birthday ASCII Game for Chris
 */

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
static void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
static void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

/* ── ANSI colours (no-op on Windows unless ENABLE_VIRTUAL_TERMINAL_PROCESSING) */
#define COL_RESET  "\033[0m"
#define COL_YELLOW "\033[1;33m"
#define COL_CYAN   "\033[1;36m"
#define COL_MAGENTA "\033[1;35m"
#define COL_RED    "\033[1;31m"
#define COL_GREEN  "\033[1;32m"
#define COL_BLUE   "\033[1;34m"
#define COL_WHITE  "\033[1;37m"

#ifdef _WIN32
static void enable_ansi(void) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(h, &mode);
    SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
static void enable_ansi(void) {}
#endif

/* ── helpers ── */
static void clear_screen(void) { int r = system(CLEAR); (void)r; }

static void print_centered(const char *text, int width) {
    int len = (int)strlen(text);
    int pad = (width - len) / 2;
    if (pad < 0) pad = 0;
    printf("%*s%s\n", pad, "", text);
}

static void press_enter(void) {
    int c;
    printf("\n" COL_WHITE "  [ Press ENTER to continue ]" COL_RESET "\n");
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ── screens ── */
static void show_title(void) {
    clear_screen();
    printf(COL_YELLOW);
    printf("\n");
    printf("  ██╗     ███████╗██╗   ██╗███████╗██╗         ██╗   ██╗██████╗ \n");
    printf("  ██║     ██╔════╝██║   ██║██╔════╝██║         ██║   ██║██╔══██╗\n");
    printf("  ██║     █████╗  ██║   ██║█████╗  ██║         ██║   ██║██████╔╝\n");
    printf("  ██║     ██╔══╝  ╚██╗ ██╔╝██╔══╝  ██║         ██║   ██║██╔═══╝ \n");
    printf("  ███████╗███████╗ ╚████╔╝ ███████╗███████╗    ╚██████╔╝██║     \n");
    printf("  ╚══════╝╚══════╝  ╚═══╝  ╚══════╝╚══════╝     ╚═════╝ ╚═╝     \n");
    printf(COL_RESET);
    printf(COL_CYAN);
    printf("\n");
    print_centered("·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·", 70);
    print_centered("  D A Y  ·  U L T I M A T E  E D I T I O N  ", 70);
    print_centered("·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·-·", 70);
    printf(COL_RESET "\n");
    press_enter();
}

static void show_birthday_cake(void) {
    clear_screen();
    printf("\n");
    printf(COL_YELLOW "   *** HAPPY BIRTHDAY CHRIS! ***\n" COL_RESET);
    printf("\n");
    /* candles */
    printf(COL_RED    "        i   i   i   i   i\n" COL_RESET);
    printf(COL_YELLOW "        |   |   |   |   |\n" COL_RESET);
    /* cake tiers */
    printf(COL_CYAN   "      __|___|___|___|___|__\n" COL_RESET);
    printf(COL_CYAN   "     |  Happy Birthday!!  |\n" COL_RESET);
    printf(COL_CYAN   "     |_____________________|\n" COL_RESET);
    printf(COL_MAGENTA"    |~~~~~~~~~~~~~~~~~~~~~~~|\n" COL_RESET);
    printf(COL_MAGENTA"    |  * * * * * * * * * *  |\n" COL_RESET);
    printf(COL_MAGENTA"    |_______________________|\n" COL_RESET);
    printf(COL_BLUE   "   |~~~~~~~~~~~~~~~~~~~~~~~~~|\n" COL_RESET);
    printf(COL_BLUE   "   |   ~~~   ~~~   ~~~   ~~  |\n" COL_RESET);
    printf(COL_BLUE   "   |_________________________|\n" COL_RESET);
    printf("\n");
    printf(COL_GREEN  "   🎂  May your XP bar always be full!  🎂\n" COL_RESET);
    printf("\n");
    press_enter();
}

static void show_stats(void) {
    const char *stats[] = {
        "  STR  [ Strength    ] ████████████████████  MAX",
        "  INT  [ Intelligence] ████████████████████  MAX",
        "  CHA  [ Charisma    ] ████████████████████  MAX",
        "  DEX  [ Dexterity   ] ████████████████████  MAX",
        "  WIS  [ Wisdom      ] ████████████████████  MAX",
        "  LUC  [ Luck        ] ████████████████████  MAX",
    };
    int n = (int)(sizeof(stats) / sizeof(stats[0]));
    int i;

    clear_screen();
    printf("\n");
    printf(COL_CYAN "  ╔══════════════════════════════════════════╗\n" COL_RESET);
    printf(COL_CYAN "  ║        ⚔  CHRIS  STAT  SHEET  ⚔        ║\n" COL_RESET);
    printf(COL_CYAN "  ╠══════════════════════════════════════════╣\n" COL_RESET);

    for (i = 0; i < n; i++) {
        printf(COL_CYAN "  ║" COL_RESET);
        printf(COL_GREEN " %s " COL_RESET, stats[i]);
        printf(COL_CYAN "║\n" COL_RESET);
        sleep_ms(200);
    }

    printf(COL_CYAN "  ╠══════════════════════════════════════════╣\n" COL_RESET);
    printf(COL_CYAN "  ║" COL_RESET COL_YELLOW "  CLASS : Legend  |  LEVEL : ∞            " COL_RESET COL_CYAN "║\n" COL_RESET);
    printf(COL_CYAN "  ╚══════════════════════════════════════════╝\n" COL_RESET);
    printf("\n");
    press_enter();
}

#define NUM_QUESTIONS 3

static void run_quiz(void) {
    typedef struct { const char *q; const char *opts[4]; int correct; } Question;
    Question qs[NUM_QUESTIONS] = {
        {
            "What is the best birthday gift?",
            {"A) Socks", "B) A new game", "C) Nothing", "D) More socks"},
            2
        },
        {
            "How many candles are on Chris's cake today?",
            {"A) A few", "B) A lot", "C) Infinite", "D) All of them"},
            3
        },
        {
            "What's the final boss of birthdays?",
            {"A) Mondays", "B) Getting older", "C) Cake calories", "D) Running out of wishes"},
            1
        },
    };

    int score = 0;
    int i, choice;
    char buf[64];

    clear_screen();
    printf(COL_MAGENTA "\n  🎮  BIRTHDAY QUIZ MINI-GAME  🎮\n\n" COL_RESET);

    for (i = 0; i < NUM_QUESTIONS; i++) {
        int j;
        printf(COL_WHITE "  Q%d: %s\n" COL_RESET, i + 1, qs[i].q);
        for (j = 0; j < 4; j++) {
            printf("      %s\n", qs[i].opts[j]);
        }
        printf(COL_CYAN "  Your answer (1-4): " COL_RESET);
        if (fgets(buf, sizeof(buf), stdin) == NULL) break;
        choice = atoi(buf);
        if (choice - 1 == qs[i].correct) {
            printf(COL_GREEN "  ✔ Correct!\n\n" COL_RESET);
            score++;
        } else {
            printf(COL_RED   "  ✘ Nice try! The answer was %s\n\n" COL_RESET,
                   qs[i].opts[qs[i].correct]);
        }
        sleep_ms(500);
    }

    printf(COL_YELLOW "  Score: %d / %d\n" COL_RESET, score, NUM_QUESTIONS);
    if (score == NUM_QUESTIONS) {
        printf(COL_GREEN "  🏆 Perfect score! You truly know birthdays!\n" COL_RESET);
    } else {
        printf(COL_CYAN "  🎂 Not bad — more cake grants +INT!\n" COL_RESET);
    }
    press_enter();
}

static void show_final_message(void) {
    clear_screen();
    printf("\n");
    printf(COL_YELLOW "  ╔════════════════════════════════════════════╗\n" COL_RESET);
    printf(COL_YELLOW "  ║                                            ║\n" COL_RESET);
    printf(COL_YELLOW "  ║    🎉  CONGRATULATIONS, CHRIS!  🎉         ║\n" COL_RESET);
    printf(COL_YELLOW "  ║                                            ║\n" COL_RESET);
    printf(COL_YELLOW "  ║  You have successfully leveled up!         ║\n" COL_RESET);
    printf(COL_YELLOW "  ║  Your quest log has been updated.          ║\n" COL_RESET);
    printf(COL_YELLOW "  ║  May this year bring +9999 happiness.      ║\n" COL_RESET);
    printf(COL_YELLOW "  ║                                            ║\n" COL_RESET);
    printf(COL_YELLOW "  ║           Happy Birthday! 🎂               ║\n" COL_RESET);
    printf(COL_YELLOW "  ║                                            ║\n" COL_RESET);
    printf(COL_YELLOW "  ╚════════════════════════════════════════════╝\n" COL_RESET);
    printf("\n");
    printf(COL_WHITE "  [Press ENTER to exit]\n" COL_RESET);
    { int c; while ((c = getchar()) != '\n' && c != EOF); }
}

int main(void) {
    enable_ansi();

    show_title();
    show_birthday_cake();
    show_stats();
    run_quiz();
    show_final_message();

    return 0;
}
