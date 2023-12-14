#include <stdio.h>
#include <math.h>

float Sigmoid(float input)
{
	float output = 0.0f;

    // ln(3.40282347e+38) ~= -88.72
    if (input <= -88.72f)
    {
        output = 0.0f;
    }
    else
    {
        output = 1.0f / (1.0f + expf(-input));
    }

	return output;
}

float Tanh(float input)
{
	return tanhf(input);
}

float HardTanh(float input, float fMin, float fMax)
{
	float output = 0.0f;

    if (input > fMax)
    {
        output = fMax;
    }
    else if (input < fMin)
    {
        output = fMin;
    }
    else
    {
        output = input;
    }

	return output;
}

float Relu(float input)
{
    return ((input >= 0) ? input : 0);
}

float PReLu(float input, float fWeight)
{
    return ((input >= 0) ? input : input * fWeight);
}

int main(void)
{
	printf("Sigmoid(5.0): %f\n", Sigmoid(5.0));
	printf("Sigmoid(0.0): %f\n", Sigmoid(0.0));
	printf("Sigmoid(-5.0): %f\n", Sigmoid(-5.0));

	printf("Tanh(5.0): %f\n", Tanh(5.0));
	printf("Tanh(0.0): %f\n", Tanh(0.0));
	printf("Tanh(-5.0): %f\n", Tanh(-5.0));

	printf("HardTanh(5.0): %f\n", HardTanh(5.0, -100, 100));
	printf("HardTanh(0.0): %f\n", HardTanh(0.0, -100, 100));
	printf("HardTanh(-5.0): %f\n", HardTanh(-5.0, -100, 100));
	printf("HardTanh(5.0): %f\n", HardTanh(5.0, -1, 1));
	printf("HardTanh(0.0): %f\n", HardTanh(0.0, -1, 1));
	printf("HardTanh(-5.0): %f\n", HardTanh(-5.0, -1, 1));

	printf("Relu(5.0): %f\n", Relu(5.0));
	printf("Relu(0.0): %f\n", Relu(0.0));
	printf("Relu(-5.0): %f\n", Relu(-5.0));

	printf("PReLu(5.0): %f\n", PReLu(5.0, 0.01));
	printf("PReLu(0.0): %f\n", PReLu(0.0, 0.01));
	printf("PReLu(-5.0): %f\n", PReLu(-5.0, 0.01));
}