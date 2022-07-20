#include <iostream>
using namespace std;

int main()
{
	//print para lingua portuguesa
	setlocale(LC_ALL, "Portuguese");
	
    //Declaracao de variaveis:
    int idade,sexo,sintomas,dias=0,ajuda=0,teste,rteste=0;
    int i,q1=0,q2=0,q3=0,q4=0,q5=0;
    int mediaI=0,diasM=0;
    float pessoas;
    
    //Entradas:
    cout << "\nQuantas pessoas participam da pesquisa? ";
    cin >> pessoas;
    cout << "\n---------------------------------------------------\n\n";
    
    for (i=1;i<=pessoas;i++){
    
    cout << "Idade da pessoa: ";
    cin >> idade;
    
    cout << "Sexo da pessoa (1- Masculino 2- Feminino): ";
    cin >> sexo;
    
    cout << "Teve sintomas do CODIV-19? (1- Sim 2-Não): ";
    cin >> sintomas;
    
    if (sintomas == 1){
    cout <<  "Por quantos dias a pessoa teve sintoma?: ";
    cin >> dias;
        
    cout << "Precisou procurar ajuda médica? (1- Emergência, 2- Consulta Médica, 3- Não): ";
    cin >> ajuda;
    }
    
    cout << "Realizou algum teste de covid? (1- Sim 2- Não): ";
    cin >> teste;
   
   if (teste == 1){
    cout << "Qual foi o resultado do teste? (1- Positivo 2- Negativo): ";
    cin >> rteste;
    
    }//Fim for.
    
    cout << "\n---------------------------------------------------\n\n";
    
    //A quantidade de pessoas assintomáticas (O exame deu positivo, mas não teve sintomas).
    if (sintomas == 2 && rteste == 1 ){
        q1++;
    }
    
    //Qual o percentual de pessoas com mais de 65 anos que procuraram um atendimento de Emergência. 
    if (idade>65 && ajuda==1){
        q2++;
    }
    //A média de duração (dias) dos sintomas do coronavírus entre todos os entrevistados da pesquisa.
    if (sintomas == 1){
        diasM = diasM + dias;
        q3++;
    }
    
    //A quantidade de pessoas que tiveram sintomas e não precisaram procurar ajuda médica.
    if (sintomas == 1 && ajuda == 3){
        q4++;
    }
    
    //A média de idade das mulheres que tiverem sintomas e o teste deu negativo.
    if (sexo == 2 && sintomas == 1 && rteste == 2){
        mediaI += idade;
        q5++;
    }
    
    }//fim for
    
    printf ("\nResultado:\n\n");
    
    //Saidas:
    cout << "Quantidade de pessoas assintomáticas: " << q1 << endl;
    cout << "Percentual de pessoas com mais de 65 anos que procuraram um atendimento de Emergência: " << q2 *100/(i-1) << "%" << endl;
    
    if (dias <= 0){
        cout << "Pacientes sem sintomas do coronavírus\n";
    }
        else{
        cout << "Média de duração dos sintomas do coronavírus entre todos os entrevistados da pesquisa: " << diasM/q3 << " dias" <<endl;
        }
    
    cout << "Quantidade de pessoas que tiveram sintomas e não precisaram procurar ajuda médica: " << q4 << endl;
    
    if (q5==0){
        cout << "Não houveram mulheres entrevistadas que tiveram sintomas e com teste deu negativo";
    }
        else {
        cout << "Média de idade das mulheres que tiverem sintomas e o teste deu negativo: " << mediaI/q5 << endl;
        }
    
    return 0;
}

