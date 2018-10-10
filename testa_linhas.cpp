// Copyright [2018] <Ana Paula Martins Tarchetti>"  [legal/copyright]
#include <gtest/gtest.h>
#include "linhas.cpp"
TEST(LinhasTest, exemplo_comum) {
    FILE *arquivo_1 = fopen("exemplo_1.cpp", "r");
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo_1);
}

TEST(LinhasTest, exemplo_linhas_vazias) {
    FILE *arquivo_2 = fopen("exemplo_2.cpp", "r");
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo_2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

