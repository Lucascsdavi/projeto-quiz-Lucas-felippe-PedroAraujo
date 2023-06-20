#include <iostream>
#include <string>
#include <locale.h>
#include <vector>

#ifdef _WIN32
#define CLEAR_COMMAND "CLS"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;

struct Usuario {
    string nome;
    string senha;
};

vector<Usuario> usuarios;

int op1;
string nome1;

void opcoes() {
    system(CLEAR_COMMAND);

    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;
    cout << "PROJETO : Lucas , Felippe, Pedro Araujo"<<endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"<<endl;


    cout << "[1] SIGNIN" << endl;
    cout << "[2] LOGIN" << endl;
    cout << "[3] SAIR" << endl;


    cout << "Escolha uma das op��es: ";
    cin >> op1;
}

void signIn() {
    system(CLEAR_COMMAND);

    string nomeUsuario, senha;

    cout << "Nome de usu�rio: ";
    cin >> nomeUsuario;

    cout << "Senha: ";
    cin >> senha;


    for (const auto& usuario : usuarios) {
        if (usuario.nome == nomeUsuario && usuario.senha == senha) {
            cout << "Ol� "<<nome1<<"!!, Login bem-sucedido!" << endl;
            system("PAUSE");
            return;
        }
    }

    cout << "Nome de usu�rio ou senha inv�lidos." << endl;
    system("PAUSE");
}

void signUp() {
    system(CLEAR_COMMAND);

    string nomeUsuario, senha;

    cout << "Digite um email novo de usu�rio: ";
    cin >> nomeUsuario;

    cout << "Digite uma senha: ";
    cin >> senha;

    cout << "Digite seu nome completo: ";
    cin.ignore();
    getline(cin, nome1);





    for (const auto& usuario : usuarios ) {
        if (usuario.nome == nomeUsuario) {
            cout << "Nome de usu�rio j� est� em uso. Tente novamente." << endl;
            system("PAUSE");
            return;
        }
    }


    Usuario novoUsuario;
    novoUsuario.nome = nomeUsuario;
    novoUsuario.senha = senha;
    usuarios.push_back(novoUsuario);

    cout << "Usu�rio registrado com sucesso!" << endl;
    system("PAUSE");
}

int main() {
    setlocale(LC_ALL, "");

    bool sair = false;

    while (!sair) {



        opcoes();

        if (op1 == 1) {
            signUp();
        } else if (op1 == 2) {
            signIn();
        } else if (op1 == 3) {
            cout << "Saindo..." << endl;
            sair = true;
        } else {
            cout << "Op��o inv�lida." << endl;
            system("PAUSE");
        }

        cout << endl;
    }

    return 0;
}



