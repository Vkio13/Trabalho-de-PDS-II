#ifndef USUARIO_H
#define USUARIO_H
/**
 * @file usuario.hpp
 * @brief Classe onde estão armazenados os usuarios
 * @version 1.6
 * @date 2022-12-05
 * @details TAD com função principal de 
 * fazer o login e ter acesso aos dados
 * sendo eles os gastos e outros inseridos
 * em Dados.hpp, específico do usuário.
 * 
 * @copyright GNU General Public License 
 * 
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include <cstdlib>

/**
         * @brief Armazena dados de um usuário.
         *
         * @details Guarda informações importantes e individuais de cada usuário.
         *
         */      
    class Usuario{
/**
         * @brief Nome do usuário.
         *
         */ 
        std::string _usuario;
            /**
         * @brief ID do usuário.
         *
         */ 
        int _id;
            /**
         * @brief Consta se o usuário está logado ou não.
         *
         */ 
        bool _logado;
    public : 
/**
         * @brief Constrói o objeto Usuario.
         *
         */ 
        Usuario();
/**
         * @brief Destrutor do objeto Usuario.
         *
         */ 
        ~Usuario();
 /**
         * @brief Cria um usuário novo.
         * @param nome Nome do usuário a ser criado.
         * @param senha Senha de login do usuário.
         */
        void criarUsuario(std::string nome, std::string senha);
 /**
         * @brief Efetua login de um determinado usuário.
         * @param nome Nome do usuário.
         * @param senha Senha de login do usuário.
         * 
         */
        void entrarUsuario(std::string nome, std::string senha);
             /**
         * @brief Procura um determinado usuário.
         * @param innome Nome do usuário a ser encontrado.
         * 
         */
        int procuraUsuario(std::string innome);
             /**
         * @brief Edita a senha de um usuário.
         * @param insenha Senha a ser definida.
         * 
         */
        void editarSenha(std::string insenha);
             /**
         * @brief Deleta um usuário.
         * @param innome Nome do usuário a ser deletado.
         * 
         */
        void deletarUsuario(std::string innome);
             /**
         * @brief Redefine informações do usuário.
         * 
         */
        std::string replace(std::string n, char c, char s);
             /**
         * @brief Faz logout de um determinado usuário.
         * 
         */
        void sair();
        //void verifica();
             /**
         * @brief Diz se o usuário está logado ou não.
         * @return True se o usuário está logado ou False se não
         * 
         */
        bool getLogado();
};
 /**
         * @brief Classe de exceção de Usuário.
         * 
         */
class Excecao_Usuario : std::exception{
    public : 
    const char* what() const noexcept;
};
#endif
