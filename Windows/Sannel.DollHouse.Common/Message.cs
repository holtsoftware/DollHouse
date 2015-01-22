using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.DollHouse.Common
{
	public abstract class Message
	{
		public static Message FromBytes(byte[] bytes)
		{
			if (bytes == null)
			{
				throw new ArgumentNullException("bytes");
			}

			if (bytes.Length < 2)
			{
				throw new ArgumentException("bytes is not long enough", "bytes");
			}

			Message message;

			switch (bytes[0])
			{
				case (byte)ComponentEnum.Light:
					message = new LightMessage();
					break;

				default:
					return null;
			}

			message.ComponentId = bytes[1];

			if (message.Load(bytes))
			{
				return message;
			}
			else
			{
				return null;
			}
		}

		protected abstract bool Load(byte[] bytes);

		public ComponentEnum ComponentType { get; set; }

		public byte ComponentId { get; set; }
	}
}
