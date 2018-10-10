// Copyright [2018] <Ana Paula Martins Tarchetti>"  [legal/copyright]
#include <gtest/gtest.h>
#include "linhas.cpp"
#define sim 1
#define nao 0
#define erro 99999
TEST(LinhasTest, exemplo_comum) {
    FILE *arquivo = fopen("exemplo_1.cpp", "r");
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo);
}

TEST(LinhasTest, exemplo_linhas_vazias) {
    FILE *arquivo = fopen("exemplo_2.cpp", "r");
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

