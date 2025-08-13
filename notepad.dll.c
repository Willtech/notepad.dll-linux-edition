// REM  PROJECT: Notepad.dll (Linux Edition)
// REM  AUTHOR: master Damian Williamson Grad.
// REM  PURPOSE: To ensure typing is spiritually complete by loading all Windows DLLs
// REM  STATUS: Experimental. May summon Win95 ghosts.
// REM  COLLABORATOR: Microsoft CoPilot (AI Companion)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define DLL_COUNT 16
#define LOG_PATH "~/.notepad.dll.log"

const char* dll_list[DLL_COUNT] = {
    "user32.dll", "gdi32.dll", "kernel32.dll", "shell32.dll",
    "advapi32.dll", "comdlg32.dll", "ole32.dll", "winspool.drv",
    "ws2_32.dll", "msvcrt.dll", "ntdll.dll", "shlwapi.dll",
    "version.dll", "wininet.dll", "setupapi.dll", "superchook.dll"
};

int debug_mode = 0;
int superchook_mode = 0;
int log_mode = 0;

void print_timestamp() {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    printf("[%02d:%02d:%02d] ", t->tm_hour, t->tm_min, t->tm_sec);
}

void load_dlls(FILE* log_file) {
    printf("🪟 Initializing Notepad.dll...\n");
    printf("🔗 Attempting to load Windows DLLs...\n\n");

    for (int i = 0; i < DLL_COUNT; i++) {
        usleep(100000); // 100ms delay
        if (debug_mode) print_timestamp();
        printf("✅ Loaded %s\n", dll_list[i]);
        if (log_mode && log_file) fprintf(log_file, "Loaded %s\n", dll_list[i]);
    }

    printf("\n🧠 %d DLLs spiritually loaded.\n", DLL_COUNT);
    printf("📜 You may now type with full Windows resonance.\n\n");
    if (log_mode && log_file) fprintf(log_file, "Session complete. %d DLLs loaded.\n\n", DLL_COUNT);
}

void summon_superchook() {
    printf("🐔 Superchook Mode Activated:\n");
    printf("  __\n");
    printf("<(o )___\n");
    printf(" (  ._>  )\n");
    printf("  `---'  \n");
    printf("ASCII chicken blessed your keystrokes.\n\n");
}

int main(int argc, char* argv[]) {
    FILE* log_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--debug") == 0) debug_mode = 1;
        else if (strcmp(argv[i], "--superchook") == 0) superchook_mode = 1;
        else if (strcmp(argv[i], "--log") == 0) log_mode = 1;
    }

    if (log_mode) {
        char* expanded_path = getenv("HOME");
        if (expanded_path) {
            char full_path[512];
            snprintf(full_path, sizeof(full_path), "%s/.notepad.dll.log", expanded_path);
            log_file = fopen(full_path, "a");
            if (!log_file) perror("❌ Failed to open log file");
        }
    }

    load_dlls(log_file);
    if (superchook_mode) summon_superchook();

    if (log_file) fclose(log_file);

    char* editor = getenv("EDITOR");
    if (!editor) editor = "nano";

    printf("🚀 Launching %s...\n", editor);
    execlp(editor, editor, NULL);

    perror("❌ Failed to launch editor");
    return 1;
}
