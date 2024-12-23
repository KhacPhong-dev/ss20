#include <stdio.h>
#include <string.h>

typedef struct {
    char id[20];
    char title[50];
    char author[50];
    float price;
    char category[30];
} Book;

Book books[100];
int book_count = 0;

void input_books() {
    printf("Nhap so luong sach: ");
    scanf("%d", &book_count);
    getchar();
    for (int i = 0; i < book_count; i++) {
        printf("\nNhap thong tin sach %d:\n", i + 1);
        printf("Ma sach: "); fgets(books[i].id, sizeof(books[i].id), stdin);
        printf("Ten sach: "); fgets(books[i].title, sizeof(books[i].title), stdin);
        printf("Tac gia: "); fgets(books[i].author, sizeof(books[i].author), stdin);
        printf("Gia tien: "); scanf("%f", &books[i].price); getchar();
        printf("The loai: "); fgets(books[i].category, sizeof(books[i].category), stdin);
        books[i].id[strcspn(books[i].id, "\n")] = '\0';
        books[i].title[strcspn(books[i].title, "\n")] = '\0';
        books[i].author[strcspn(books[i].author, "\n")] = '\0';
        books[i].category[strcspn(books[i].category, "\n")] = '\0';
    }
}

void display_books() {
    printf("\nDanh sach sach:\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d. Ma: %s | Ten: %s | Tac gia: %s | Gia: %.2f | The loai: %s\n",
               i + 1, books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
    }
}

void add_book() {
    if (book_count >= 100) {
        printf("Danh sach da day.\n");
        return;
    }
    int vitri;
    printf("Nhap vi tri muon them sach (1-%d): ", book_count + 1);
    scanf("%d", &vitri);
    getchar();
    if (vitri < 1 || vitri > book_count + 1) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = book_count; i >= vitri; i--) {
        books[i] = books[i - 1];
    }
    printf("\nNhap thong tin sach moi:\n");
    printf("Ma sach: "); fgets(books[vitri - 1].id, sizeof(books[vitri - 1].id), stdin);
    printf("Ten sach: "); fgets(books[vitri - 1].title, sizeof(books[vitri - 1].title), stdin);
    printf("Tac gia: "); fgets(books[vitri - 1].author, sizeof(books[vitri - 1].author), stdin);
    printf("Gia tien: "); scanf("%f", &books[vitri - 1].price); getchar();
    printf("The loai: "); fgets(books[vitri - 1].category, sizeof(books[vitri - 1].category), stdin);
    books[vitri - 1].id[strcspn(books[vitri - 1].id, "\n")] = '\0';
    books[vitri - 1].title[strcspn(books[vitri - 1].title, "\n")] = '\0';
    books[vitri - 1].author[strcspn(books[vitri - 1].author, "\n")] = '\0';
    books[vitri - 1].category[strcspn(books[vitri - 1].category, "\n")] = '\0';
    book_count++;
    printf("Da them sach thanh cong.\n");
}

void delete_book() {
    char id[20];
    printf("Nhap ma sach can xoa: ");
    getchar();
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].id, id) == 0) {
            for (int j = i; j < book_count - 1; j++) {
                books[j] = books[j + 1];
            }
            book_count--;
            printf("Da xoa sach thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma nay.\n");
}

void update_book() {
    char id[20];
    printf("Nhap ma sach can cap nhat: ");
    getchar();
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].id, id) == 0) {
            printf("\nNhap thong tin moi:\n");
            printf("Ten sach: "); fgets(books[i].title, sizeof(books[i].title), stdin);
            printf("Tac gia: "); fgets(books[i].author, sizeof(books[i].author), stdin);
            printf("Gia tien: "); scanf("%f", &books[i].price); getchar();
            printf("The loai: "); fgets(books[i].category, sizeof(books[i].category), stdin);
            books[i].title[strcspn(books[i].title, "\n")] = '\0';
            books[i].author[strcspn(books[i].author, "\n")] = '\0';
            books[i].category[strcspn(books[i].category, "\n")] = '\0';
            printf("Da cap nhat thong tin sach.\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ma nay.\n");
}

void sort_books() {
    int choice;
    printf("Sap xep theo gia (1-Tang, 2-Giam): ");
    scanf("%d", &choice);
    for (int i = 0; i < book_count - 1; i++) {
        for (int j = i + 1; j < book_count; j++) {
            if ((choice == 1 && books[i].price > books[j].price) ||
                (choice == 2 && books[i].price < books[j].price)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Da sap xep sach.\n");
}

void search_book() {
    char title[50];
    printf("Nhap ten sach can tim: ");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("\nKet qua tim kiem:\n");
    for (int i = 0; i < book_count; i++) {
        if (strstr(books[i].title, title)) {
            printf("Ma: %s | Ten: %s | Tac gia: %s | Gia: %.2f | The loai: %s\n",
                   books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. Nhap thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia\n");
        printf("7. Tim kiem sach theo ten\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                input_books(); 
                break;
            case 2: 
                display_books(); 
                break;
            case 3: 
                add_book(); 
                break;
            case 4:     
                delete_book(); 
                break;
            case 5: 
                update_book(); 
                break;
            case 6: 
                sort_books(); 
                break;
            case 7: 
                search_book(); 
                break;
            case 8: 
                printf("Thoat chuong trinh.\n");
                 break;
            default: 
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);
    return 0;
}
