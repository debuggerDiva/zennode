let price = [20.0, 40.0, 50.0];
let A, B, C;
let a1, b1, c1;
let ten = 10.0, zero = 0.0;

console.log("Enter the Quantity of product A");
A = parseFloat(prompt());
console.log("Do you want to wrap product A as a Gift (Y/N): ");
a1 = prompt();

console.log("Enter the Quantity of product B");
B = parseFloat(prompt());
console.log("Do you want to wrap product B as a Gift (Y/N): ");
b1 = prompt();

console.log("Enter the Quantity of product C");
C = parseFloat(prompt());
console.log("Do you want to wrap product C as a Gift (Y/N): ");
c1 = prompt();

let cartTotal = A * price[0] + B * price[1] + C * price[2];
let giftTotal = (a1 === 'Y' ? A : 0) + (b1 === 'Y' ? B : 0) + (c1 === 'Y' ? C : 0);
let shippingCost = Math.ceil((A + B + C ) / 10) * 5;

let totalItems = A + B + C;

let flat_10_discount = 0, bulk_5_discount = 0, bulk_10_discount = 0, tiered_50_discount = 0;

if (cartTotal > 200) {
    flat_10_discount = 10;
}

bulk_5_discount = (A > 10 ? price[0] * A * 0.05 : 0) + (B > 10 ? price[1] * B * 0.05 : 0) + (C > 10 ? price[2] * C * 0.05 : 0);

bulk_10_discount = ((A + B + C) > 20 ? cartTotal * 0.1 : 0);

if ((A + B + C) > 30) {
    tiered_50_discount += (A > 15 ? (A - 15) * (price[0] / 2) : 0);
    tiered_50_discount += (B > 15 ? (B - 15) * (price[1] / 2) : 0);
    tiered_50_discount += (C > 15 ? (C - 15) * (price[2] / 2) : 0);
}

let mxDiscount = 0;
let discountType = "None";

if (mxDiscount < flat_10_discount) {
    mxDiscount = flat_10_discount;
    discountType = "flat_10_discount";
}

if (mxDiscount < bulk_5_discount) {
    mxDiscount = bulk_5_discount;
    discountType = "bulk_5_discount";
}

if (mxDiscount < bulk_10_discount) {
    mxDiscount = bulk_10_discount;
    discountType = "bulk_10_discount";
}

if (mxDiscount < tiered_50_discount) {
    mxDiscount = tiered_50_discount;
    discountType = "tiered_50_discount";
}

let finalCost = cartTotal - mxDiscount;
finalCost += giftTotal;
finalCost += shippingCost;

console.log(`Product Name: A  Quantity : ${A}  Cost : ${A * price[0]}`);
console.log(`Product Name: B  Quantity : ${B}  Cost : ${B * price[1]}`);
console.log(`Product Name: C  Quantity : ${C}  Cost : ${C * price[2]}`);
console.log(`SubTotal : ${cartTotal}`);
console.log(`The discount name applied & the discount amount : ${discountType}  ${mxDiscount}`);
console.log(`The shipping fee & the gift wrap fee : ${giftTotal + shippingCost}`);
console.log(`Total Cost: ${finalCost}`);
