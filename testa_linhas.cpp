// Copyright [2018] <Ana Paula Martins Tarchetti>"  [legal/copyright]
#include <gtest/gtest.h>
#include "linhas.cpp"
TEST(LinhasTest, exemplo_comum) {
    FILE *arquivo = fopen("exemplo_1.cpp", "r");
    if (arquivo != NULL) {
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo);
    }
}

TEST(LinhasTest, exemplo_linhas_vazias) {
    FILE *arquivo = fopen("exemplo_2.cpp", "r");
    if (arquivo != NULL) {
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo);
    }
}

TEST(LinhasTest, exemplo_comentarios_barra_barra) {
    FILE *arquivo = fopen("exemplo_3.cpp", "r");
    if (arquivo != NULL) {
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo);
    }
}

TEST(LinhasTest, exemplo_comentarios_barra_asterisco) {
    FILE *arquivo = fopen("exemplo_4.cpp", "r");
    if (arquivo != NULL) {
    ASSERT_EQ(5, quantidade_linhas(arquivo));
    fclose(arquivo);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

