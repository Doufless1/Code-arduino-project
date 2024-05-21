#ifndef COMPONENT_GYROSCOPE_HPP
#define COMPONENT_GYROSCOPE_HPP

class GyroScope
{
	public:
		GyroScope();

		void GyroScope::generate();

		int GyroScope::angle_x() const;
		int GyroScope::angle_y() const;
		int GyroScope::angle_z() const;
	
	private:
		int accelerometer_x_;
		int accelerometer_y_;
		int accelerometer_z_;
};

#endif // COMPONENT_GYROSCOPE_HPP
