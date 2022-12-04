#ifndef USUARIO_H
#define USUARIO_H
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
/**
 * @file usuario.hpp
 * @brief Classe onde estão armazenados os usuarios
 * @version 1.5
 * @date 2022-12-01
 * @details TAD com função principal de 
 * fazer o login e ter acesso aos dados
 * sendo eles os gastos e outros inseridos
 * em Dados.hpp, específico do usuário.
 * 
 * @copyright GNU General Public License 
 * 
 */
/**
         * @brief Gera um relatorio de todas as 
         * categorias
         *
         * @details Recebe as categorias e as insere
         * dentro do relatório.
         *
         */      
    class Usuario{
/**
         * @brief Lista de categorias
         *
         * @param categorias Lista do tipo Categoria
         * contendo todas as categorias registradas
         * e seus dados.
         *
         */ 
        std::string _usuario;
        int _id;
        bool _logado;
    public : 
/**
         * @brief Constrói o objeto Usuario.
         *
         * @param categorias Lista do tipo Categoria
         * contendo todas as categorias registradas
         * e seus dados.
         *
         */ 
        Usuario();
/**
         * @brief Destrutor do objeto Usuario.
         *
         */ 
        //~Usuario();
 /**
         * @brief .
         * 
         */
        void criarUsuario(std::string nome, std::string senha);
 /**
         * @brief Printa o relatório geral.
         * 
         */
        void entrarUsuario(std::string nome, std::string senha);
        int procuraUsuario(std::string innome);
        void editarSenha(std::string insenha);
        void deletarUsuario(std::string innome);
        std::string replace(std::string n, char c, char s);
    };
#endif
