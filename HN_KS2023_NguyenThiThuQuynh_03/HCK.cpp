#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct {
	int array[MAX];
	int top;
} Stack;
// khoi tao mang stack
void inital(Stack* stack) {
	stack->top = -1;
}
//kiem tra ngan xep co bi day hay khong
int isFull(Stack* stack) {
	if(stack->top > MAX - 1 ) {
		return 1;
	}
	return 0;
}
//kiem tra rong hay ko
int isEmpty(Stack* stack) {
	if(stack->top == -1) {
		return 1;
	}
	return 0;
}
// them phan tu vao ngan xep
void push(Stack* stack,int value) {
	if(isFull(stack)) {
		printf("Ngan xep bi day khong the them %d .\n",value);
	} else {
		stack->array[++stack->top] = value;
		printf("Them thanh cong %d vao ngan xep.\n",value);
	}

}
// lay phan tu khoi ngan xep
int pop(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Ngan xep trong khong the lay ra .  \n");
		return -1;
	} else {
		return stack->array[stack->top--];
	}
}
// kiem tra phan tu tren cung ngan xxep
int peek(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Ngan xep trong! khong co phan tu tren cung.\n");
		return -1;
	} else {
		return stack->array[stack->top];

	}
}

// lay kich thuoc ngan xep
int size(Stack* stack) {
	return stack->top + 1;
}
// In toan bo ngan xep
void printStack(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Ngan xep trong.\n");
	} else {
		printf("Phan tu ngan xep: ");
		for(int i = 0; i <= stack->top; i++) {
			printf("%d ",stack->array[i]);
		}
		printf("\n");
	}
}
//xoa toan bo ngan xep
void clearStack(Stack* stack) {
	stack->top = -1;
	printf("Da xoa.\n");
}
// In ra cac phan tu thu tu nguoc lai cua ngan xep
void printReverse(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Ngan xep trong.\n");
	} else {
		printf("In ra cac phan tu thu tu nguoc lai:");
		for (int i = stack->top; i >= 0; i--) {
			printf("%d ", stack->array[i]);
		}
		printf("\n");
	}
}


int main () {
	int value;
	Stack stack;
	inital(&stack);
	do {
		printf("\n================MENU================\n");
		printf("1. Them phan tu vao ngan xep\n");
		printf("2. Lay phan tu khoi ngan xep\n");
		printf("3. Kiem tra phan tu tren cung ngan xep\n");
		printf("4. Kiem tra ngan xep co rong khong\n");
		printf("5. Lay kich thuoc ngan xep\n");
		printf("6. In toan bo ngan xep\n");
		printf("7. Xoa toan bo ngan xep\n");
		printf("8. In ra cac phan tu thu tu nguoc lai\n");
		printf("9. Thoat\n");
		printf(" Moi ban chon : \n");
		int choice;
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("Nhap gia tri de them : ");
				scanf("%d", &value);
				push(&stack, value);
				break;

			case 2:
				value = pop(&stack);
				if (value != -1) {
					printf("Phan tu da lay ra: %d\n", value);
				}
				break;

			case 3:
				value = peek(&stack);
				if (value != -1) {
					printf("Phan tu tren cung: %d\n", value);
				}
				break;

			case 4:
				if (isEmpty(&stack)) {
					printf("Ngan xep dang trong.\n");
				} else {
					printf("Ngan xep khong rong.\n");
				}
				break;

			case 5:
				printf("Kich thuoc ngan xep: %d,\n", size(&stack));
				break;

			case 6:
				printStack(&stack);
				break;

			case 7:
				clearStack(&stack);
				break;

			case 8:
				printReverse(&stack);
				break;

			case 9:
				printf("Tam Biet\n");
				exit(0);

			default:
				printf("Lua chon khong hop le! Vui long thu lai.\n");
		}
	} while(1);
	return 0;
}
