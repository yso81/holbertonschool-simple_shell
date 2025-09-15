#include <stdio.h>
#include <errno.h>

int main() {
    // Specify the path to your swap file here.
    const char* filename = "/getline.c.swp";

    // Attempt to delete the file.
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
        return 1; // Return an error code
    }

    return 0;
}

