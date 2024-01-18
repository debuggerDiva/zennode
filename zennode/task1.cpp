#include<bits/stdc++.h>

using namespace std;

class Shop
{
    public:
    int price_A,price_B,price_C,gift_wrap_fee,ship_fee_perPackage;

    Shop(){
        price_A = 20;
        price_B = 40;
        price_C = 50;

        gift_wrap_fee = 1;
        ship_fee_perPackage = 5;
    }

    double flat_10_discount(double totalPrice){
        if(totalPrice > 200){
            return totalPrice - 10;
        }
        return totalPrice;
    }

    double bulk_5_discount(int A, int B, int C, double totalPrice){
        if(A>10){
            totalPrice -= (A*price_A)*0.05;
        }
        if(B>10){
            totalPrice -= (B*price_B)*0.05;
        }
        if(C>10){
            totalPrice -= (C*price_C)*0.05;
        }
        return totalPrice;

    }

    double bulk_10_discount(double totalPrice, double totalUnit){
        if(totalUnit > 20){
            totalPrice -= (totalPrice*0.1);
        }
        return totalPrice;
    }

    double tiered_50_discount(int A, int B, int C, double totalPrice,double totalUnit){
        if(totalUnit > 30){
            if(A > 15){
            totalPrice -= (A-15)*price_A*0.50;
        }
        if(B > 15){
            totalPrice -= (B-15)*price_B*0.50;
        }
        if(C > 15){
            totalPrice -= (C-15)*price_C*0.50;
        }

        }
        return totalPrice;
    }

    double getShipCharge(double totalUnit){
        return ceil(totalUnit/10)*ship_fee_perPackage;
    }

};

int main(){
    Shop S;
    int quant_A,quant_B,quant_C;
    int wrapReq_A,wrapReq_B,wrapReq_C;

    cout<<"Enter quantity for Product A: ";
    cin >> quant_A;

    cout<<"Enter quantity for Product B: ";
    cin >> quant_B;

    cout<<"Enter quantity for Product C: ";
    cin >> quant_C;

    cout << "Wrap Product A as a gift? (If yes , press 1 else 0) : ";
    cin >>  wrapReq_A;

    cout << "Wrap Product B as a gift? (If yes , press 1 else 0): ";
    cin >>  wrapReq_B;

    cout << "Wrap Product C as a gift? (If yes , press 1 else 0): ";
    cin >>  wrapReq_C;

    int pA_total = quant_A* S.price_A;
    int pB_total = quant_B* S.price_B;
    int pC_total = quant_C* S.price_C;

    double totalUnit = quant_A + quant_B + quant_C;
    double totalPrice = pA_total + pB_total + pC_total;
    double shipping_fee = S.getShipCharge(totalUnit);

    int wrap_fee = 0;
    if(wrapReq_A){
        wrap_fee += quant_A;
    }
    if(wrapReq_B){
        wrap_fee += quant_B;
    }
    if(wrapReq_C){
        wrap_fee += quant_C;
    }

    set<pair<double,string>>disc;

    disc.insert({S.flat_10_discount(totalPrice),"flat_10_discount"});
    disc.insert({S.bulk_5_discount(quant_A,quant_B,quant_C,totalPrice),"bulk_5_discount"});
    disc.insert({S.bulk_10_discount(totalPrice,totalUnit),"bulk_10_discount"});
    disc.insert({S.tiered_50_discount(quant_A,quant_B,quant_C,totalPrice,totalUnit),"tiered_50_discount"});

    pair<double,string> bestDisc = (*(disc.begin())).first == totalPrice ? make_pair(totalPrice,"No discount") : *(disc.begin());

     cout << "Product A Quantity: " << quant_A << " Total amount: $" << pA_total << endl;
    cout << "Product B Quantity: " << quant_B << " Total amount: $" << pB_total << endl;
    cout << "Product C Quantity: " << quant_C << " Total amount: $" << pC_total << endl;
    cout << "Subtotal: $" << totalPrice << endl;
    cout << "Discount Scheme: " << bestDisc.second << endl;
    cout << "Discout Amount: $" << totalPrice - bestDisc.first << endl;
    cout << "The Shipping Fee: $" << shipping_fee << endl;
    cout << "Gift Wrap Fee: $" << wrap_fee << endl;
    cout << "Total $" << bestDisc.first + wrap_fee + shipping_fee << endl;



}
