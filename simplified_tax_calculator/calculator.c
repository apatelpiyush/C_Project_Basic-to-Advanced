#include <stdio.h>
#include <conio.h>

void mat(){
    char ma;
    printf("The tax structure in India is a three-tier structure: local municipal bodies, state, and central government. Taxation in India is broadly classified into two types:-\n");
    printf("1)Direct tax\n2)Indirect tax:-\n");
    printf("----------------------------------------------------------------------\n");
    ma=getchar();
    while(ma == '\n') ma=getchar();
    switch(ma){
        case '1': {printf("Direct tax is levied on people's income or profits. For example, a taxpayer pays the government for different purposes, including income tax, personal property tax, FBT, etc. The burden has to be borne by the person on whom the tax is levied and cannot be passed on to someone else. Central Board of Direct Taxes (CBDT) governs and administers the Direct Tax.\n");
                  printf("\e[1m\e[4mAdvantages\e[0m:- Individuals with lower incomes pay lower taxes than people with higher incomes, i.e, progressive in nature. Curbs inflation and reduces inequalities. Sense of certainty as both the government and taxpayer are aware of what and when to be paid.\n");
                  printf("\e[1m\e[4mDisadvantages\e[0m:- Fraudulent practices through which taxpayers often pay lower taxes or avoid taxes. The documentation process can be complex and time-consuming. The burden cannot be transferred to any other in the chain.\n");
        }break;

        case '2':{ printf("Indirect tax is levied by the government on goods and services. Therefore, it can be shifted from one tax-paying individual to another. E.g; the wholesaler can pass it on to retailers, who then pass it on to customers. Therefore, customers bear the brunt of indirect taxes. The Central Board of Indirect Taxes and Customs (CBIC) governs and administers indirect taxes.\n");
                  printf("\e[1m\e[4mAdvantages\e[0m:- Every Individual contributes to nation-building. Easily collectable from the end consumer.Fair Distribution of tax, i.e, essential goods are charged lesser compared to goods that are luxurious. The burden of paying can be transferred to the end consumer.\n");
                  printf("\e[1m\e[4mDisadvantages\e[0m:- Increase in overall price of goods and service. Consumers often lack knowledge of the taxes paid. It is regressive in nature. The amount received in tax is often unpredictable as the tax paid depends on the goods and services purchased.\n");
        }break;

        default:
                  printf("Please Enter Proper Input To Obtain Information!!\n");
    }
    if(ma=='1' || ma=='2')
    printf("\n Other than direct and indirect taxes, there are few other taxes existing which are important to be known like Property tax, Registration fees, Toll tax, education cess, entertainment tax, and professional tax.\n");
    printf("----------------------------------------------------------------------\n");
}

void tti(){
    printf("However, it is also crucial to know the different types of taxes in India implemented in the taxation system. Here's all about the types of taxes and the range of rates applied :-\n");
    printf("----------------------------------------------------------------------\n");
    char *names[]={"Income Tax","Corporate Tax","Securities Transcation Tax","Capital Gains Tax","Gift Tax","Wealth Tax","Sales Tax","Service Tax","Octroi Duty","Custom Duty","Value added tax(VAT)","Goods and Services Tax(GST)","Property Tax","Registration Fees","Toll Tax","Education Cess","Entertainment Tax","Professional Tax"};
    char *rates[]={"5%-30%","25% or 35%","0.02%-0.1%","12.5%(Long Term) or 20%(Short Term)","For >50,000 included in income tax","1% for >30Lakhs","18%","15%","3%-5%","0%-100%","12.5%-15%","0%, 5%, 12%, 18%, 28%","5%-20%","1%","150-600 Rupee","4%","10%-30%", "200-2500 Rupee"};
    int n=sizeof(names)/sizeof(names[0]);
    for(int z=0;z<n;z++){
        printf("%d)\e[4m\e[1m%s\e[0m:- %s\n", z+1,names[z],rates[z]);
    }
    printf("----------------------------------------------------------------------\n");
} 

void gst(){
    printf("Select the rate from the given list whose items you wish to Check-out:\n");
    printf("----------------------------------------------------------------------\n");
    char *per[]={"0%","0.25%","3%","5%","12%","18%","28%"};
    for(int y=0;y<sizeof(per)/sizeof(per[0]);y++){
        printf("%d)\e[1m\e[4m%s\n\e[0m", y+1,per[y]);
    }
    printf("----------------------------------------------------------------------\n");
    printf("\n");
    char mb= getchar();
    while (mb == '\n') mb = getchar();  
    switch(mb){
        case '1':{
                char *zero[]={"Milk", "kajal", "eggs", "educational services", "curd", "lassi", "health services","drawing books", "unpacked foodgrains", "unbranded atta/maida", "unpacked panner", "besan", "unbranded natural honey", "fresh vegetables", "salt", "prasad", "jaggery"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                    printf("%d)%s\n",w+1,zero[w]);
                }}break;
        case '2':{
                char *zero[]={"Non-industrial diamonds", "unworked stones", "synthetic/reconstructed precious stones"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                printf("%d)%s\n",w+1,zero[w]);
                }}break;
        case '3':{
                char *zero[]={"Imitation jewellry", "precious metal", "natural/cultured pearl", "diamonds(excludes non-industrial)", "precious stones", "silver","gold"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                printf("%d)%s\n",w+1,zero[w]);
                }}break;                  
        case '4':{
                char *zero[]={"sugar","packed panner","tea","coal","edible oils","raisin", "domestic LPG", "roasted coffee beans", "kerosene,milk powder", "cashew", "footwear", "fabric", "matting spices", "agarbatti", "indian sweets", "life-saving drugs", "coffee"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                printf("%d)%s\n",w+1,zero[w]);
                }}break;
        case '5':{
                char *zero[]={"butter", "ghee", "processed food", "almonds", "mobiles", "fruit juice", "fruits", "chutney", "jam", "jelly", "packed coconut water", "umbrella"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                printf("%d)%s\n",w+1,zero[w]);
                }}break;
        case '6':{
                char *zero[]={"hair oil", "capital goods", "toothpaste", "soap", "ice cream", "pasta", "toiletries", "corn", "flakes", "soups", "printers", "computers"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                printf("%d)%s\n",w+1,zero[w]);
                }}break;
        case '7':{
                char *zero[]={"small cars(+1% or 3% cess)", "high-end motorcycles(+15%cess)", "AC and fridge", "luxury items like BMWs", "cigrattes", "aerated drinks(+15% cess)"};
                for(int w=0;w<sizeof(zero)/sizeof(zero[0]);w++){
                printf("%d)%s\n",w+1,zero[w]);
                }}break;
        default:
                printf("Enter Valid Tax Rate !!\n");        
    }
    printf("----------------------------------------------------------------------\n");
}

void itc(){
    printf("\n\tWelcome To Income Tax Calculator.\n");
    float salary;
    char regime='2';
    printf("Enter The Tax Regime:- \n1)\e[4m\e[1mOld Regime\e[0m \n\e[4m\e[1mAny Other Input Will Apply New Regime\e[0m\n");
    scanf(" %c", &regime);
    printf("----------------------------------------------------------------------\n");
    if(regime=='1'){
        float income, tax = 0;
        float deduction_80C = 0, deduction_health = 0, deduction_edu = 0, deduction_home = 0;
        float total_deductions = 0, taxable_income;

        printf("Enter your annual income (in Rs): ");
        scanf("%f", &income);

        printf("Enter amount under Section 80C (max Rs 1,50,000): ");
        scanf("%f", &deduction_80C);
        if (deduction_80C > 150000) deduction_80C = 150000;

        printf("Enter health insurance and medical expenses deduction (max Rs 25,000): ");
        scanf("%f", &deduction_health);
        if (deduction_health > 25000) deduction_health = 25000;

        printf("Enter education loan interest deduction: ");
        scanf("%f", &deduction_edu);

        printf("Enter home loan interest deduction (max Rs 2,00,000): ");
        scanf("%f", &deduction_home);
        if (deduction_home > 200000) deduction_home = 200000;

        total_deductions = deduction_80C + deduction_health + deduction_edu + deduction_home;
        taxable_income = income - total_deductions;
        
        if (taxable_income <= 250000) {
            tax = 0;
        }
        else if (taxable_income <= 500000){
            tax = (taxable_income - 250000) * 0.05;
        }
        else if (taxable_income <= 1000000) {
            tax = 12500 + (taxable_income - 500000) * 0.20;
        }
        else {
            tax = 112500 + (taxable_income - 1000000) * 0.30;
        }

        if (taxable_income < 0  || taxable_income<500000){
            taxable_income = 0;
            tax=0;
        }
        printf("\n\e[1m\e[4mGross Income:\e[0m Rs %.2f", income);
        printf("\n\e[1m\e[4mTotal Deductions:\e[0m Rs %.2f", total_deductions);
        printf("\n\e[1m\e[4mTaxable Income:\e[0m Rs %.2f", taxable_income);
        printf("\n\e[1m\e[4mTotal Tax to be paid:\e[0m Rs %.2f\n", tax);
    }
    else{
        float tax = 0.0;
        float income, standard_deduction = 75000, pension_deduction = 0, family_pension = 0;
        float LTCG_exemption = 125000;
        float employer_pension_pct = 0.14;  
        float taxable_income;

        printf("Enter your gross salary income: ");
        scanf("%f", &income);

        printf("Enter employer's contribution to pension scheme: ");
        scanf("%f", &pension_deduction);

        printf("Enter family pension amount received: ");
        scanf("%f", &family_pension);
        if (family_pension > 25000)
            family_pension = 25000;
        if (income <= 400000) {
                tax = 0;
        } else if (income <= 800000) {
            tax = (income - 400000) * 0.05;
        } else if (income <= 1200000) {
            tax = 20000 + (income - 800000) * 0.10;
        } else if (income <= 1600000) {
            tax = 60000 + (income - 1200000) * 0.15;
        } else if (income <= 2000000) {
            tax = 120000 + (income - 1600000) * 0.20;
        } else if (income <= 2400000) {
            tax = 200000 + (income - 2000000) * 0.25;
        } else {
            tax = 300000 + (income - 2400000) * 0.30;
        }

        taxable_income = income - standard_deduction - pension_deduction - family_pension;

        if (taxable_income < 0  || taxable_income<1200000){
            taxable_income = 0;
            tax=0;
        }

        printf("\e[1m\e[4mTaxable Income:\e[0m Rs. %.2f\n", taxable_income);
        printf("\e[1m\e[4mIncome Tax to be paid under New Regime:\e[0m Rs. %.2f\n", tax);
    }
    printf("----------------------------------------------------------------------\n");
}

int main() {
    char ch;

    printf("\t\t \e[1m\e[4mWELCOME TO INDIAN TAX CALCULATION PAGE\e[0m \t\t\n ");
    printf("----------------------------------------------------------------------\n");
    printf("Taxes are an obligatory expense enforced on the individual by the state and central government. They are one of the government's most significant income sources, helping them build our country's economy and infrastructure. Therefore, as a responsible citizen, you must pay taxes.\n");
    printf("----------------------------------------------------------------------\n");
    printf("Features Available On Our Page:-\n 1)\e[1m\e[4mMore About Taxes\e[0m \n 2)\e[1m\e[4mTypes Of Taxes In India\e[0m \n 3)\e[1m\e[4mCurrent GST Rates In India\e[0m \n 4)\e[1m\e[4mIncome Tax Calculator\e[0m\n");
    
    ch=getchar();
    while (ch == '\n') ch = getchar();  
    switch(ch){
        case '1': {mat();}
        break;
        case '2': {tti();}
        break;
        case '3': {gst();}
        break;
        case '4': {itc();}
        break;
        default:
        printf("Enter Correct Input To Access The Features!!\n");
    }
    
    printf("----------------------------------------------------------------------\n");

    printf("\t\tThank You For Choosing Our Page. Have A Great Day.\t\t\n");
    printf("----------------------------------------------------------------------\n");
    printf("For Any Further Queries, Please Contact:\n");
    char *issue[]={"e-filing and Centralized Processing Center","AIS and Reporting Portal","TDS Reconciliation Analysis and Correction Enabling System","Tax Information Network - NSDL","Demand Management - Tax Payer Demand Facilitation Center"};
    long long int number[]={18001030025,18001034215,18001030344,912027218080,18003090130};
    for(int i=0;i<sizeof(issue)/sizeof(issue[0]);i++){
        printf("%d)%s - %lld\n", i+1,issue[i],number[i]);
    }
    printf("----------------------------------------------------------------------\n");
    printf("Please Give The User Experience:-\n1)Very Poor\n2)Poor\n3)Average\n4)Good\n5)Excellent\n");
    char r;
    scanf(" %c",&r);  
    switch(r){
        case '1': printf("We Will Improve The Experience utmost :((\n");break;
        case '2': printf("Will Improve Performance :(\n");break;
        case '3': printf("Will Do Better Next Time!!\n");break;
        case '4': printf("Thank You Very Much :)\n");break;
        case '5': printf("Happy To Serve You :))\n");break;
        default: printf("Enter Proper Rating!!\n");
    }
    printf("----------------------------------------------------------------------\n");
    return 0;
}

