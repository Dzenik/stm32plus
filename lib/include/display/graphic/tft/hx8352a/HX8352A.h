/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once


#include "display/graphic/tft/hx8352a/HX8352AColour.h"
#include "display/graphic/tft/hx8352a/HX8352AOrientation.h"
#include "display/graphic/tft/hx8352a/HX8352AGamma.h"
#include "display/graphic/tft/hx8352a/commands/AllCommands.h"


namespace stm32plus {
	namespace display {

		/**
		 * Generic HX8352A template. The user can specialise based on the desired colour
		 * depth, orientation and access mode.
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		class HX8352A : public HX8352AColour<TColourDepth,TAccessMode,TPanelTraits>,
									 public HX8352AOrientation<TOrientation,TAccessMode,TPanelTraits> {

			protected:
				TAccessMode& _accessMode;
				uint8_t _backlightPercentage;

			public:
				HX8352A(TAccessMode& accessMode);

				void initialise();

				void applyGamma(HX8352AGamma& gamma) const;
				void sleep() const;
				void wake() const;
				void beginWriting() const;
				void setScrollArea(uint16_t y,uint16_t height) const;
		};


		/**
		 * Constructor. Pass the access mode reference up the hierarchy where it'll get stored in the
		 * common base class for use by all.
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::HX8352A(TAccessMode& accessMode)
			: HX8352AColour<TColourDepth,TAccessMode,TPanelTraits>(accessMode),
			  HX8352AOrientation<TOrientation,TAccessMode,TPanelTraits>(accessMode),
			  _accessMode(accessMode) {
		}


		/**
		 * Initialise the LCD. Do the reset sequence.
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline void HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::initialise() {

			// reset the device

			this->_accessMode.reset();
		}


		/**
		 * Apply the panel gamma settings
		 * @param gamma The gamma class containing the one value
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline void HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::applyGamma(HX8352AGamma& gamma) const {
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+0,gamma[0]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+1,gamma[1]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+2,gamma[2]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+3,gamma[3]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+4,gamma[4]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+5,gamma[5]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+6,gamma[6]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+7,gamma[7]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+8,gamma[8]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+9,gamma[9]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+10,gamma[10]);
			this->_accessMode.writeCommand(hx8352a::GAMMA_1+11,gamma[11]);
		}


		/**
		 * Send the panel to sleep
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline void HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::sleep() const {
		}


		/**
		 * Wake the panel up
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline void HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::wake() const {
		}


		/**
		 * Issue the command that allows graphics ram writing to commence
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline void HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::beginWriting() const {
		}


		/**
		 * Set the scroll area to a full-width rectangle region
		 * @param y The y-co-ord of the region
		 * @param height The height of the region
		 */

		template<Orientation TOrientation,ColourDepth TColourDepth,class TAccessMode,class TPanelTraits>
		inline void HX8352A<TOrientation,TColourDepth,TAccessMode,TPanelTraits>::setScrollArea(uint16_t y,uint16_t height) const {
		}
	}
}