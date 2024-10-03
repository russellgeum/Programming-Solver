// 복소수 연산기 만들기
#include <iostream>


// 복소수 타입 클래스
class Complex {
    private:
        double real;
        double imag;

    public: 
        Complex() { real = 0; imag = 0;}
        Complex (double real_, double imag_) { real = real_; imag = imag_;}

        double GetReal() { return real; }
        double GetImag() { return imag; }
        void SetReal(double real_) { real = real_; }
        void SetImag(double imag_) { imag = imag_; } 
};


// class Complex를 상속받아 계산기 구현
class ComplexCalculator : public Complex {
    private:
        Complex c1;
        Complex c2;
        Complex result;

    public:
        // 피연산자의 생성자
        ComplexCalculator(Complex c1, Complex c2) {
            this->c1.SetReal(c1.GetReal());
            this->c1.SetImag(c1.GetImag());
            this->c2.SetReal(c2.GetReal());
            this->c2.SetImag(c2.GetImag());
            // 결과값 초기화
            this->result.SetReal(0);
            this->result.SetImag(0);
        }
        // // 피연산자의 소멸자
        // ~ComplexCalculator() {
        //     delete[] c1;
        //     delete[] c2;
        // }

        // 레퍼런스 변수를 사용하여 계산 (메모리 효율화))
        Complex Add(Complex& c1, Complex& c2) {
            this->result.SetReal(c1.GetReal() + c2.GetReal());
            this->result.SetImag(c1.GetImag() + c2.GetImag());
            return this->result;
        }

        Complex Sub(Complex& c1, Complex& c2) {
            this->result.SetReal(c1.GetReal() - c2.GetReal());
            this->result.SetImag(c1.GetImag() - c2.GetImag());
            return this->result;
        }

        Complex Mul(Complex& c1, Complex& c2) {
            this->result.SetReal(c1.GetReal() * c2.GetReal() - c1.GetImag() * c2.GetImag());
            this->result.SetImag(c1.GetReal() * c2.GetImag() + c1.GetImag() * c2.GetReal());
            return this->result;
        }

        Complex Div(Complex& c1, Complex& c2) {
            this->result.SetReal((c1.GetReal() * c2.GetReal() + c1.GetImag() * c2.GetImag()) /
                (c2.GetReal() * c2.GetReal() + c2.GetImag() * c2.GetImag()));
            this->result.SetImag((c1.GetImag() * c2.GetReal() - c1.GetReal() * c2.GetImag()) /
                (c2.GetReal() * c2.GetReal() + c2.GetImag() * c2.GetImag()));
            return this->result;
        }
};  


// 복소수 객체를 입력받아 복소수 형태로 출력하는 함수
void printComplex(Complex& c) {
    std::cout << c.GetReal() << " + " << c.GetImag() << "i" << std::endl;
}


int main() {
    Complex c1(5, 10);
    Complex c3(2, 3);
    ComplexCalculator calculator(c1, c3);
    

    Complex result = calculator.Add(c1, c3);
    printComplex(result);

    result = calculator.Sub(c1, c3);
    printComplex(result);
}