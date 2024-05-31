#ifndef COMPONENT_GYROSCOPE_HPP
#define COMPONENT_GYROSCOPE_HPP

class GyroScope
{
	public:
		GyroScope(const int A4, const int A5);

		double pitch() const;
        float The_Angle() const;
        void SetupGyro() const;
};

#endif // COMPONENT_GYROSCOPE_HPP
