
#include "Stdafx.h"
#include "OutstationCommandHandlerAdapter.h"
#include "Conversions.h"


namespace Automatak
{
	namespace DNP3
	{
		namespace Adapter
		{

			OutstationCommandHandlerAdapter::OutstationCommandHandlerAdapter(Automatak::DNP3::Interface::ICommandHandler^ proxy) : proxy(proxy)
			{

			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Supports(const opendnp3::ControlRelayOutputBlock& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Supports(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Supports(const opendnp3::AnalogOutputInt32& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Supports(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Supports(const opendnp3::AnalogOutputInt16& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Supports(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Supports(const opendnp3::AnalogOutputFloat32& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Supports(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Supports(const opendnp3::AnalogOutputDouble64& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Supports(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Perform(const opendnp3::ControlRelayOutputBlock& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Perform(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Perform(const opendnp3::AnalogOutputInt32& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Perform(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Perform(const opendnp3::AnalogOutputInt16& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Perform(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Perform(const opendnp3::AnalogOutputFloat32& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Perform(Conversions::ConvertCommand(arCommand), aIndex));
			}

			opendnp3::CommandStatus OutstationCommandHandlerAdapter::Perform(const opendnp3::AnalogOutputDouble64& arCommand, uint16_t aIndex)
			{
				return Conversions::ConvertCommandStatus(proxy->Perform(Conversions::ConvertCommand(arCommand), aIndex));
			}

		}
	}
}

