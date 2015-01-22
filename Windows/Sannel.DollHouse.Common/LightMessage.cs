using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.UI;

namespace Sannel.DollHouse.Common
{
	public class LightMessage : Message
	{
		public bool IsOn { get; set; }

		public Color Color { get; set; }

		protected override bool Load(byte[] bytes)
		{
			if (bytes.Length == 3)
			{
				IsOn = bytes[2] == 1;
				Color = Colors.White;
				return true;
			}
			else if (bytes.Length >= 7)
			{
				IsOn = bytes[2] == 1;
				Color = Color.FromArgb(bytes[3], bytes[4], bytes[5], bytes[6]);
				return true;
			}

			return false;
		}
	}
}
