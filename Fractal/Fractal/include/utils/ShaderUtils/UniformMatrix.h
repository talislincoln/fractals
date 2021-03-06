#ifndef UNIFORM_MATRIX_H
#define UNIFORM_MATRIX_H

#include <Fractal\include\utils\ShaderUtils\Uniform.h>
#include <FractalMath\Matrix.h>
namespace fractal {

	class UniformMatrix : public Uniform {

	public:
		UniformMatrix(const char* name);
		void loadMatrix(const fmath::Matrix4& matrix);
	private:
		fmath::Matrix4 m_matrix;
	};

}
#endif // !UNIFORM_MATRIX_H
