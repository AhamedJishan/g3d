#include "g3d/mat3.h"
#include "g3d/vec3.h"

namespace g3d
{
	mat3::mat3()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_data[i][j] = 0;
			}
		}
	}

	mat3::mat3(const float value)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_data[i][j] = (i == j) ? value : 0;
			}
		}
	}

	mat3::mat3(const float value[3][3])
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				m_data[i][j] = value[i][j];
			}
		}
	}

	mat3::mat3(const vec3& vec)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j) m_data[i][j] = vec.raw[i];
				else m_data[i][j] = 0;
			}
		}
	}


	mat3 mat3::operator+(const mat3& other) const
	{
		mat3 mat;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mat(i,j) = m_data[i][j] + other(i,j);
			}
		}
		return mat;
	}

	mat3 mat3::operator-(const mat3& other) const
	{
		mat3 mat;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				mat(i, j) = m_data[i][j] - other(i, j);
			}
		}
		return mat;
	}

	mat3 mat3::operator*(float scalar) const
	{
		mat3 mat;
		for (int i = 0; i < 9; i++)
		{
			mat(i / 3, i % 3) = scalar * this->at(i / 3, i % 3);
		}
		return mat;
	}

	mat3 mat3::operator/(float scalar) const
	{
		mat3 mat;
		for (int i = 0; i < 9; i++)
		{
			mat(i / 3, i % 3) = this->at(i / 3, i % 3) / scalar;
		}
		return mat;
	}

	mat3 mat3::operator*(const mat3& other) const
	{
		mat3 mat;

		for (int index = 0; index < 9; index++)
		{
			int i = index / 3;
			int j = index % 3;

			for (int k = 0; k < 3; k++)
			{
				mat(i, j) += this->at(i, k) * other(k, j);
			}
		}

		return mat;
	}

	bool mat3::operator==(const mat3& M) const
	{
		for (int i = 0; i < 9; i++)
		{
			if (this->at(i/3, i%3) != M(i/3, i%3)) return false;
		}
		return true;
	}

	bool mat3::operator!=(const mat3& M) const
	{
		for (int i = 0; i < 9; i++)
		{
			if (this->at(i / 3, i % 3) != M(i / 3, i % 3)) return true;
		}
		return false;
	}

	std::ostream& operator<<(std::ostream& os, const mat3& mat)
	{
		os << "{";
		for (int i = 0; i < 3; i++)
		{
			os << "(" << mat(i,0) << ", " << mat(i, 1) << ", " << mat(i, 2) << "), ";
		}
		os << "\b\b}";
		return os;
	}

}