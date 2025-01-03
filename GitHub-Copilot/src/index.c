#include <stdio.h>
#include <string.h>

int is_prefix(const char *card_number, const char *prefix) {
    return strncmp(card_number, prefix, strlen(prefix)) == 0;
}

const char* identify_card_brand(const char *card_number) {
    int length = strlen(card_number);

    if (length == 13 || length == 16) {
        if (is_prefix(card_number, "4")) return "Visa";
    }
    if (length == 16) {
        if (is_prefix(card_number, "51") || is_prefix(card_number, "52") ||
            is_prefix(card_number, "53") || is_prefix(card_number, "54") ||
            is_prefix(card_number, "55")) return "Mastercard";
        if (is_prefix(card_number, "2221") || is_prefix(card_number, "2720")) return "Mastercard";
    }
    if (length == 15) {
        if (is_prefix(card_number, "34") || is_prefix(card_number, "37")) return "American Express";
    }
    if (length == 16) {
        if (is_prefix(card_number, "4011") || is_prefix(card_number, "4312") ||
            is_prefix(card_number, "4514") || is_prefix(card_number, "4576")) return "Elo";
    }
    if (length == 13 || length == 16) {
        if (is_prefix(card_number, "38") || is_prefix(card_number, "60")) return "Hipercard";
    }
    if (length == 14 || length == 16) {
        if (is_prefix(card_number, "36") || is_prefix(card_number, "38") || is_prefix(card_number, "39")) return "Diners Club";
    }
    if (length == 16) {
        if (is_prefix(card_number, "6011") || (is_prefix(card_number, "622") && atoi(card_number + 3) >= 126 && atoi(card_number + 3) <= 925)) return "Discover";
    }
    if (length == 16 || length == 19) {
        if (is_prefix(card_number, "35")) return "JCB";
        if (is_prefix(card_number, "62")) return "UnionPay";
    }
    if (length == 16) {
        if (is_prefix(card_number, "50")) return "Aura";
    }
    if (length == 16) {
        return "Banescard";
    }

    return "Unknown";
}

int main() {
    char card_number[20];
    printf("Digite o número do cartão: ");
    scanf("%19s", card_number);

    const char* brand = identify_card_brand(card_number);
    printf("A bandeira do cartão é: %s\n", brand);

    return 0;
}